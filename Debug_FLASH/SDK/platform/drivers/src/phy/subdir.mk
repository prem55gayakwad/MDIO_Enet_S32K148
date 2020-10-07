################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy.c" \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_generic.c" \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_tja110x.c" \

C_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy.c \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_generic.c \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_tja110x.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/phy/phy.o \
./SDK/platform/drivers/src/phy/phy_generic.o \
./SDK/platform/drivers/src/phy/phy_tja110x.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/phy/phy.d" \
"./SDK/platform/drivers/src/phy/phy_generic.d" \
"./SDK/platform/drivers/src/phy/phy_tja110x.d" \

OBJS += \
./SDK/platform/drivers/src/phy/phy.o \
./SDK/platform/drivers/src/phy/phy_generic.o \
./SDK/platform/drivers/src/phy/phy_tja110x.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/phy/phy.o" \
"./SDK/platform/drivers/src/phy/phy_generic.o" \
"./SDK/platform/drivers/src/phy/phy_tja110x.o" \

C_DEPS += \
./SDK/platform/drivers/src/phy/phy.d \
./SDK/platform/drivers/src/phy/phy_generic.d \
./SDK/platform/drivers/src/phy/phy_tja110x.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/phy/phy.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/phy/phy.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/phy/phy.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/phy/phy_generic.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_generic.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/phy/phy_generic.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/phy/phy_generic.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/phy/phy_tja110x.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/phy/phy_tja110x.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/phy/phy_tja110x.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/phy/phy_tja110x.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


