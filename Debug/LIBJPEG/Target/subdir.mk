################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIBJPEG/Target/jdata_conf.c 

OBJS += \
./LIBJPEG/Target/jdata_conf.o 

C_DEPS += \
./LIBJPEG/Target/jdata_conf.d 


# Each subdirectory must supply rules for building sources it contributes
LIBJPEG/Target/%.o LIBJPEG/Target/%.su: ../LIBJPEG/Target/%.c LIBJPEG/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../LIBJPEG/App -I../LIBJPEG/Target -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/LibJPEG/include -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../Middlewares/ST/AI/Inc -I../X-CUBE-AI/App -I../X-CUBE-AI -I../Drivers/BSP/STM32F429I-Discovery -I"/Users/edoardo/STM32CubeIDE/workspace_1.10.1/stm32f429-ai-teachablemachine/Drivers/BSP/Components/Common" -I"/Users/edoardo/STM32CubeIDE/workspace_1.10.1/stm32f429-ai-teachablemachine/Utilities/Fonts" -I"/Users/edoardo/STM32CubeIDE/workspace_1.10.1/stm32f429-ai-teachablemachine/Drivers/BSP/STM32F429I-Discovery" -I"/Users/edoardo/STM32CubeIDE/workspace_1.10.1/stm32f429-ai-teachablemachine/Drivers/BSP/Components/stmpe811" -I"/Users/edoardo/STM32CubeIDE/workspace_1.10.1/stm32f429-ai-teachablemachine/Drivers/BSP/Components/ili9341" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LIBJPEG-2f-Target

clean-LIBJPEG-2f-Target:
	-$(RM) ./LIBJPEG/Target/jdata_conf.d ./LIBJPEG/Target/jdata_conf.o ./LIBJPEG/Target/jdata_conf.su

.PHONY: clean-LIBJPEG-2f-Target

