all:

-include config.mk
-include $(shell find -name '*.d')

CLEAN += $$(find -name '*.[od]')
Makefile: config.mk
	touch $@
config.mk:
	touch $@

CFLAGS += -MMD

%.o: %.c Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.cpp Makefile
	$(CXX) -c $(CFLAGS) -o $@ $<

%.o: %.s Makefile
	$(CC) -x assembler -c $(CFLAGS) -o $@ $< 

%: %.o Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter %.o,$^) -o $@ $(LIBS)

%.so: CFLAGS += -fPIC
%.so: %.o Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter %.o, $^) $(LIBS) -shared -Wl,-soname,$@ -o $@

.PHONY: clean
clean:
	rm -rf $(CLEAN)
