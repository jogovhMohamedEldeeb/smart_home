################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
smart_home_1v.lss \

FLASH_IMAGE += \
smart_home_1v.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: smart_home_1v.elf secondary-outputs

# Tool invocations
smart_home_1v.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smart_home_1v.map -mmcu=atmega32 -o "smart_home_1v.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smart_home_1v.lss: smart_home_1v.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smart_home_1v.elf  >"smart_home_1v.lss"
	@echo 'Finished building: $@'
	@echo ' '

smart_home_1v.hex: smart_home_1v.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex smart_home_1v.elf  "smart_home_1v.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smart_home_1v.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 smart_home_1v.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) smart_home_1v.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
