#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile that supports 2 platforms: HOST(Linux) and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	<FILE>.o - Builds <FILE>.o object file
# 	<FILE>.i - Generate the preprocessed output <FILE>.i
# 	<FILE>.asm - Generate assembly output <FILE>.asm
# 
# 	compile-all : Compiles all files, doesn't build
# 	build: Compile all object files and link into a final executable
# 	all: same as build
# 	clean: removes all generated files.
# 
# Platform Overrides:
# 	CPU -  ARM Cortex Architecture(cortex-m4)
# 	ARCH - ARM Architecture (thumb)
# 	SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM), MSP432)
	
	#Architecture Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)\
		   -march=armv7e-m -mfloat-abi=hard \
		   -mfpu=fpv4-sp-d16
	OBJDUMP=arm-none-eabi-objdump
	#Size utility
	SIZE = arm-none-eabi-size

	#compiler flags and defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
else ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	
	OBJDUMP = objdump
	
	#Size utility
	SIZE = size

endif

TARGET = c1m2

CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)


OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

PPF = $(SOURCES:.c=.i)

%.i : %.c
	$(CC) $(INCLUDES) -E -c $< $(CFLAGS) -o $@

ASF = $(SOURCES:.c=.asm)

%.asm : %.c
	$(CC) $(INCLUDES) -S -c $< $(CFLAGS) -o $@

DEPS = $(SOURCES:.c=.d)

%.d : %.c
	$(CC) $(INCLUDES) -M -c $< $(CFLAGS) -o $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $< >> $@

FILES = *.asm *.o *.d *.i

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build : all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $@
	$(SIZE) $(TARGET).out

.PHONY: clean
clean: 
	rm -f $(FILES) $(TARGET).out $(TARGET).map $(PPF) $(DEPS) $(OBJS) $(ASF)
