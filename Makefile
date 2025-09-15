# ------------------------------------------------------------
# Project settings
# ------------------------------------------------------------
PROJECT := $(notdir $(CURDIR))

# Toolchain
CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size

# Directories
SRC_DIR     := Src
STARTUP_DIR := startup
HAL_DIR     := Drivers/STM32F1xx_HAL_Driver/Src
BUILD_DIR   := Build

# Files
LINKER      := linker/stm32f103c8t6.ld
STARTUP     := $(STARTUP_DIR)/startup_stm32f103xb.s

# Includes + Defines
INCS := -IInc \
        -IDrivers/CMSIS/Core/Include \
        -IDrivers/CMSIS/Include \
        -IDrivers/CMSIS/Device/ST/STM32F1xx/Include \
        -IDrivers/STM32F1xx_HAL_Driver/Inc

DEFS := -DUSE_HAL_DRIVER -DSTM32F103xB

# Flags
CFLAGS  := -mcpu=cortex-m3 -mthumb -O2 -ffunction-sections -fdata-sections -g3 -Wall $(INCS) $(DEFS)
LDFLAGS := -T$(LINKER) -Wl,--gc-sections -specs=nosys.specs

# Sources
C_SOURCES   := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(HAL_DIR)/*.c)
ASM_SOURCES := $(STARTUP)
OBJS        := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(C_SOURCES))) \
               $(patsubst %.s, $(BUILD_DIR)/%.o, $(notdir $(ASM_SOURCES)))

# ------------------------------------------------------------
# Rules
# ------------------------------------------------------------

all: $(BUILD_DIR)/$(PROJECT).bin

# Build dir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile C
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(HAL_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ASM
$(BUILD_DIR)/%.o: $(STARTUP_DIR)/%.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link
$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)
	$(CC) -mcpu=cortex-m3 -mthumb $^ -o $@ $(LDFLAGS)
	$(SIZE) $@

# Binary
$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf
	$(OBJCOPY) -O binary $< $@
	@echo "Build succeeded: $@"

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

