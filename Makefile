all:

CFLAGS = -g -O2 -Wall -Wextra -Wstack-usage=512 -Iinclude
LDFLAGS = -Lld
TARGET = stm32f303vc
CLEAN = src/*.o src/*.map

include mk/arm.mk

GDB = $(TC)-gdb

all: main

main: LDFLAGS+= -Wl,-Map=src/main.map
src/main: src/main.o

.PHONY: gdb
gdb:
	$(GDB) -x stm32.gdb scr/main
