################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32g4xx_hal_msp.c \
../Core/Src/stm32g4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g4xx.c 

CPP_SRCS += \
../Core/Src/bldc.cpp \
../Core/Src/curr_sens.cpp \
../Core/Src/data_types.cpp \
../Core/Src/driver.cpp \
../Core/Src/filter.cpp \
../Core/Src/hall_encoder.cpp \
../Core/Src/main_bridge.cpp \
../Core/Src/math_utils.cpp 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32g4xx_hal_msp.d \
./Core/Src/stm32g4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g4xx.d 

OBJS += \
./Core/Src/bldc.o \
./Core/Src/curr_sens.o \
./Core/Src/data_types.o \
./Core/Src/driver.o \
./Core/Src/filter.o \
./Core/Src/hall_encoder.o \
./Core/Src/main.o \
./Core/Src/main_bridge.o \
./Core/Src/math_utils.o \
./Core/Src/stm32g4xx_hal_msp.o \
./Core/Src/stm32g4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g4xx.o 

CPP_DEPS += \
./Core/Src/bldc.d \
./Core/Src/curr_sens.d \
./Core/Src/data_types.d \
./Core/Src/driver.d \
./Core/Src/filter.d \
./Core/Src/hall_encoder.d \
./Core/Src/main_bridge.d \
./Core/Src/math_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G473xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G473xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/bldc.cyclo ./Core/Src/bldc.d ./Core/Src/bldc.o ./Core/Src/bldc.su ./Core/Src/curr_sens.cyclo ./Core/Src/curr_sens.d ./Core/Src/curr_sens.o ./Core/Src/curr_sens.su ./Core/Src/data_types.cyclo ./Core/Src/data_types.d ./Core/Src/data_types.o ./Core/Src/data_types.su ./Core/Src/driver.cyclo ./Core/Src/driver.d ./Core/Src/driver.o ./Core/Src/driver.su ./Core/Src/filter.cyclo ./Core/Src/filter.d ./Core/Src/filter.o ./Core/Src/filter.su ./Core/Src/hall_encoder.cyclo ./Core/Src/hall_encoder.d ./Core/Src/hall_encoder.o ./Core/Src/hall_encoder.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/main_bridge.cyclo ./Core/Src/main_bridge.d ./Core/Src/main_bridge.o ./Core/Src/main_bridge.su ./Core/Src/math_utils.cyclo ./Core/Src/math_utils.d ./Core/Src/math_utils.o ./Core/Src/math_utils.su ./Core/Src/stm32g4xx_hal_msp.cyclo ./Core/Src/stm32g4xx_hal_msp.d ./Core/Src/stm32g4xx_hal_msp.o ./Core/Src/stm32g4xx_hal_msp.su ./Core/Src/stm32g4xx_it.cyclo ./Core/Src/stm32g4xx_it.d ./Core/Src/stm32g4xx_it.o ./Core/Src/stm32g4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32g4xx.cyclo ./Core/Src/system_stm32g4xx.d ./Core/Src/system_stm32g4xx.o ./Core/Src/system_stm32g4xx.su

.PHONY: clean-Core-2f-Src

