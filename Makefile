# Ok, i dont understand anything, is just... code and more codes
# this supposed to compile the kernel, but im not sure if the internet's guy was right

# Compiler and linker
CC = i686-elf-gcc
LD = i686-elf-ld
AS = nasm

# Flags
CFLAGS = -ffreestanding -O2 -Wall -Wextra -I src
LDFLAGS = -T linker.ld -nostdlib
ASFLAGS = -f elf32

# Directories
SRC_DIR = src
MODULES_DIR = $(SRC_DIR)/Modules
BUILD_DIR = build

# Sources
C_SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(MODULES_DIR)/*.c)
ASM_SRCS := $(wildcard $(SRC_DIR)/*.asm) $(wildcard $(MODULES_DIR)/*.asm)

# Object files
C_OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRCS))
C_OBJS := $(patsubst $(MODULES_DIR)/%.c,$(BUILD_DIR)/Modules/%.o,$(C_OBJS))
C_OBJS := $(patsubst $(MODULES_DIR)/%.c,$(BUILD_DIR)/Utilities/%.o,$(C_OBJS))

ASM_OBJS := $(patsubst $(SRC_DIR)/%.asm,$(BUILD_DIR)/%.o,$(ASM_SRCS))
ASM_OBJS := $(patsubst $(MODULES_DIR)/%.asm,$(BUILD_DIR)/Modules/%.o,$(ASM_OBJS))

OBJS = $(C_OBJS) $(ASM_OBJS)

# Final binary
KERNEL_BIN = $(BUILD_DIR)/kernel.bin

# Default target
all: $(KERNEL_BIN)

# Link step
$(KERNEL_BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

# Compile .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/Modules/%.o: $(MODULES_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble .asm to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/Modules/%.o: $(MODULES_DIR)/%.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
