################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
obj/hal_appasrt.obj: ../Application/MAC/HAL/common/hal_appasrt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me -O4 --opt_for_speed=0 --include_path="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/Application" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/Application/subg" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/boards" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/boards/common" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/boards/subg" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/boards/CC13X0_LAUNCHXL" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/boards/CC1310_CC1190" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/api/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/util" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/common/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/stack/src" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/examples/rtos/CC1350_LAUNCHXL/ti154stack/stack/tirtos/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/heapmgr" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/hal/src/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/hal/src/target/_common" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/hal/src/target/_common/cc13xx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/icall/src/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/osal/src/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/services/src/aes" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/services/src/appasrt" --include_path="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/Application/Services" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/services/src/nv/cc26xx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/services/src/saddr" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/services/src/sdata" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/stack/src/icall" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/fh" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/high_level" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/rom" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/inc/cc13xx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/low_level/cc13xx" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/low_level/cc13xx/subg" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/ti154stack/tracer" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0/inc" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0/driverlib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --preinclude="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/Application/subg/features.h" --define=AUTO_START --define=NV_RESTORE --define=RF_MULTI_MODE --define=xPOWER_MEAS --define=MAX_DEVICE_TABLE_ENTRIES=50 --define=BOARD_DISPLAY_USE_UART --define=xBOARD_DISPLAY_USE_LCD --define=ONE_PAGE_NV --define=ONE_PAGE_NV_FULL_HDR --define=DEVICE_FAMILY=cc13x0 --define=DeviceFamily_CC13X0 --define=CC13XX_LAUNCHXL --define=TI154STACK --define=CCFG_FORCE_VDDR_HH=0 --define=SET_CCFG_BL_CONFIG_BL_LEVEL=0x00 --define=SET_CCFG_BL_CONFIG_BL_ENABLE=0xC5 --define=SET_CCFG_BL_CONFIG_BL_PIN_NUMBER=0x0D --define=SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE=0xC5 --define=HEAPMGR_SIZE=0 --define=USE_ICALL --define=STACK_LIBRARY --define=ICALL_LITE --define=RCN_APP_ASSERT --define=HAL_ASSERT_SPIN --define=ICALL_HOOK_ABORT_FUNC=halAssertHandler --define=xdc_runtime_Log_DISABLE_ALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xPREAMBLE_COMPATIBILITY --define=FEATURE_ENHANCED_ACK --define=FEATURE_SYSTEM_STATS --define=xSTATIC_MAC_SECURITY_DEFAULTS --define=Board_EXCLUDE_NVS_EXTERNAL_FLASH --c99 --plain_char=unsigned --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --embedded_constants=on --unaligned_access=on --enum_type=packed --wchar_t=16 --abi=eabi --common=on --fp_reassoc=off --sat_reassoc=off --asm_directory="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/collector_cc1350lp" --list_directory="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/collector_cc1350lp/obj" --obj_directory="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/collector_cc1350lp/obj" --temp_directory="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/collector_cc1350lp" --preproc_with_compile --preproc_dependency="C:/Users/Einstein/MyWorkspaceCC1350/collector_cc1350lp/collector_cc1350lp/Application/MAC/HAL/common/hal_appasrt.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


