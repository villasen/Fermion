################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CC1350_LAUNCHXL.obj: ../CC1350_LAUNCHXL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx/tirtos/" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/rfPacketTx_CC1350_LAUNCHXL_tirtos_ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/posix/ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13c0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="CC1350_LAUNCHXL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CC1350_LAUNCHXL_fxns.obj: ../CC1350_LAUNCHXL_fxns.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx/tirtos/" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/rfPacketTx_CC1350_LAUNCHXL_tirtos_ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/posix/ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13c0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="CC1350_LAUNCHXL_fxns.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ccfg.obj: ../ccfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx/tirtos/" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/rfPacketTx_CC1350_LAUNCHXL_tirtos_ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/posix/ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13c0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ccfg.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main_tirtos.obj: ../main_tirtos.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx/tirtos/" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/rfPacketTx_CC1350_LAUNCHXL_tirtos_ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/posix/ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13c0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="main_tirtos.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

rfPacketTx.obj: ../rfPacketTx.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/drivers/rfPacketTx/tirtos/" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/rfPacketTx_CC1350_LAUNCHXL_tirtos_ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/posix/ccs" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13c0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="rfPacketTx.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


