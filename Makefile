all:

CFLAGS  = -g -O2 -Wall -Wextra -Wstack-usage=512 -Iinclude
LDFLAGS = -Lld
TARGET  = stm32f303vc
CLEAN   = src/*.o src/*.map

include mk/arm.mk

GDB = $(TC)-gdb

all: main.fw

main: LDFLAGS+= -Wl,-Map=src/main.map
main: LDSCRIPT = ld/stm32f303vc-target.ld

src/main: \
  src/main.o \
  src/stm32f303vc_init.o \
  src/stm32f303vc_vtable.o

main.fw: src/main
	$(OBJCOPY) -O binary $< $@

.PHONY: gdb
gdb: src/main
	$(GDB) -x stm32.gdb src/main

.PHONY: flash
flash: main.fw
	st-flash write $< 0x8000000
