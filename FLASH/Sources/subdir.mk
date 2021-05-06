################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MCUinit.c" \
"../Sources/main.c" \
"../Sources/motor.c" \
"../Sources/sensores.c" \

C_SRCS += \
../Sources/MCUinit.c \
../Sources/main.c \
../Sources/motor.c \
../Sources/sensores.c \

OBJS += \
./Sources/MCUinit_c.obj \
./Sources/main_c.obj \
./Sources/motor_c.obj \
./Sources/sensores_c.obj \

OBJS_QUOTED += \
"./Sources/MCUinit_c.obj" \
"./Sources/main_c.obj" \
"./Sources/motor_c.obj" \
"./Sources/sensores_c.obj" \

C_DEPS += \
./Sources/MCUinit_c.d \
./Sources/main_c.d \
./Sources/motor_c.d \
./Sources/sensores_c.d \

C_DEPS_QUOTED += \
"./Sources/MCUinit_c.d" \
"./Sources/main_c.d" \
"./Sources/motor_c.d" \
"./Sources/sensores_c.d" \

OBJS_OS_FORMAT += \
./Sources/MCUinit_c.obj \
./Sources/main_c.obj \
./Sources/motor_c.obj \
./Sources/sensores_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/MCUinit_c.obj: ../Sources/MCUinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MCUinit.args" -ObjN="Sources/MCUinit_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/motor_c.obj: ../Sources/motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/motor.args" -ObjN="Sources/motor_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/sensores_c.obj: ../Sources/sensores.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/sensores.args" -ObjN="Sources/sensores_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


