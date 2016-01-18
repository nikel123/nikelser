all:

CFLAGS  = -g -O2 -Wall -Wextra -Wstack-usage=512 -Iinclude
LDFLAGS = -Lld
TARGET  = stm32f303vc
CLEAN   = src/*.o src/*.map

include mk/arm.mk

GDB = $(TC)-gdb

all: src/main

main: LDFLAGS+= -Wl,-Map=src/main.map
main: LDSCRIPT = ld/stm32f303vc-target.ld

src/main: src/main.o src/stm32f303vc_vtable.o src/stm32f303vc_init.o

.PHONY: gdb
gdb:
	$(GDB) -x stm32.gdb scr/main
