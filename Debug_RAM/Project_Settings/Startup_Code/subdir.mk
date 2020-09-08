################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/devices/S32K148/startup/gcc/startup_S32K148.S" \

S_UPPER_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/devices/S32K148/startup/gcc/startup_S32K148.S \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/startup_S32K148.o \

OBJS += \
./Project_Settings/Startup_Code/startup_S32K148.o \

OBJS_QUOTED += \
"./Project_Settings/Startup_Code/startup_S32K148.o" \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/startup_S32K148.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/devices/S32K148/startup/gcc/startup_S32K148.S
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@Project_Settings/Startup_Code/Startup_S32K148.args" -o "Project_Settings/Startup_Code/startup_S32K148.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


