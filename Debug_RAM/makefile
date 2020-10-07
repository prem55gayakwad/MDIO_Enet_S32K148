################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 25
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Generated_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include SDK/platform/devices/S32K148/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/clock/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/enet/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/phy/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include Sources/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MDIO_Enet_S32K148.elf \

EXECUTABLES_QUOTED += \
"MDIO_Enet_S32K148.elf" \

EXECUTABLES_OS_FORMAT += \
MDIO_Enet_S32K148.elf \

SECONDARY_SIZE += \
MDIO_Enet_S32K148.siz \
MDIO_Enet_S32K148.siz \

SECONDARY_SIZE_QUOTED += \
"MDIO_Enet_S32K148.siz" \
"MDIO_Enet_S32K148.siz" \

SECONDARY_SIZE_OS_FORMAT += \
MDIO_Enet_S32K148.siz \
MDIO_Enet_S32K148.siz \

SECONDARY_SIZE += \
MDIO_Enet_S32K148.siz \
MDIO_Enet_S32K148.siz \

SECONDARY_SIZE_QUOTED += \
"MDIO_Enet_S32K148.siz" \
"MDIO_Enet_S32K148.siz" \

SECONDARY_SIZE_OS_FORMAT += \
MDIO_Enet_S32K148.siz \
MDIO_Enet_S32K148.siz \


# All Target
all: warning-messages explicit-dependencies MDIO_Enet_S32K148.elf secondary-outputs

# Tool invocations
MDIO_Enet_S32K148.elf: $(OBJS) C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/devices/S32K148/linker/gcc/S32K148_256_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #26 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "MDIO_Enet_S32K148.elf" "@MDIO_Enet_S32K148.args"  $(USER_OBJS_QUOTED) 
	@echo 'Finished building target: $@'
	@echo ' '

MDIO_Enet_S32K148.siz: $(EXECUTABLES)
	@echo 'Executing target #27 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*/*.d ./*/*/*/*/*/*.d ./*/*/*/*/*/*/*.d  ./*/*.o ./*/*/*/*.o ./*/*/*/*/*/*.o ./*/*/*/*/*/*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

