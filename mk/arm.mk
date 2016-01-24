include mk/nikelmake.mk

TC ?= arm-none-eabi

CC = $(TC)-gcc
AS = $(TC)-as
LD = $(TC)-gcc
AR = $(TC)-ar
OBJCOPY = $(TC)-objcopy
OBJDUMP = $(TC)-objdump

LDSCRIPT ?= $(TARGET)

CFLAGS += $(MCU) $(FPU)
LDFLAGS += \
  $(MCU) $(FPU) \
  -Tld/$(LDSCRIPT).ld \
  -Xlinker --gc-sections

ifndef TARGET
$(error "Please define TARGET")
endif

ifeq "$(TARGET)" ""
$(error "Target is empty")
endif

include mk/$(TARGET).mk
