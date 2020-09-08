################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_driver.c" \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_hw_access.c" \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_irq.c" \

C_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_driver.c \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_hw_access.c \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_irq.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/enet/enet_driver.o \
./SDK/platform/drivers/src/enet/enet_hw_access.o \
./SDK/platform/drivers/src/enet/enet_irq.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/enet/enet_driver.d" \
"./SDK/platform/drivers/src/enet/enet_hw_access.d" \
"./SDK/platform/drivers/src/enet/enet_irq.d" \

OBJS += \
./SDK/platform/drivers/src/enet/enet_driver.o \
./SDK/platform/drivers/src/enet/enet_hw_access.o \
./SDK/platform/drivers/src/enet/enet_irq.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/enet/enet_driver.o" \
"./SDK/platform/drivers/src/enet/enet_hw_access.o" \
"./SDK/platform/drivers/src/enet/enet_irq.o" \

C_DEPS += \
./SDK/platform/drivers/src/enet/enet_driver.d \
./SDK/platform/drivers/src/enet/enet_hw_access.d \
./SDK/platform/drivers/src/enet/enet_irq.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/enet/enet_driver.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/enet/enet_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/enet/enet_driver.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/enet/enet_hw_access.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_hw_access.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/enet/enet_hw_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/enet/enet_hw_access.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/enet/enet_irq.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/drivers/src/enet/enet_irq.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/enet/enet_irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/enet/enet_irq.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


