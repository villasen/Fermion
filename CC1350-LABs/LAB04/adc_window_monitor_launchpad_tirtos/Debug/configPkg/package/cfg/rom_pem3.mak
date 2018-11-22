#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,16.9,8
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/rom_pem3.oem3.dep
package/cfg/rom_pem3.oem3.dep: ;
endif

package/cfg/rom_pem3.oem3: | .interfaces
package/cfg/rom_pem3.oem3: package/cfg/rom_pem3.c package/cfg/rom_pem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/armcl -c  -mv7M3 --code_state=16 -me --include_path="C:/Users/Einstein/MyWorkspaceCC1350/adc_window_monitor_launchpad_tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/kernel/tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/boards/CC1350_LAUNCHXL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DEVICE_FAMILY=cc13x0 --define=DeviceFamily_CC13X0 -g --c99 --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi   -qq -pdsw225 -ms --fp_mode=strict --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3   -Dxdc_cfg__xheader__='"configPkg/package/cfg/rom_pem3.h"'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_16_9_8 -O2  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oem3 $< -C   -mv7M3 --code_state=16 -me --include_path="C:/Users/Einstein/MyWorkspaceCC1350/adc_window_monitor_launchpad_tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/kernel/tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/boards/CC1350_LAUNCHXL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DEVICE_FAMILY=cc13x0 --define=DeviceFamily_CC13X0 -g --c99 --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi   -qq -pdsw225 -ms --fp_mode=strict --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3   -Dxdc_cfg__xheader__='"configPkg/package/cfg/rom_pem3.h"'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_16_9_8 -O2  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/rom_pem3.oem3: export C_DIR=
package/cfg/rom_pem3.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/;$(PATH)
package/cfg/rom_pem3.oem3: Path:=$(ti.targets.arm.elf.M3.rootDir)/bin/;$(PATH)

package/cfg/rom_pem3.sem3: | .interfaces
package/cfg/rom_pem3.sem3: package/cfg/rom_pem3.c package/cfg/rom_pem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/armcl -c -n -s --symdebug:none -mv7M3 --code_state=16 -me --include_path="C:/Users/Einstein/MyWorkspaceCC1350/adc_window_monitor_launchpad_tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/kernel/tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/boards/CC1350_LAUNCHXL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DEVICE_FAMILY=cc13x0 --define=DeviceFamily_CC13X0 -g --c99 --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3   -Dxdc_cfg__xheader__='"configPkg/package/cfg/rom_pem3.h"'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_16_9_8 -O2  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oem3 $< -C  -n -s --symdebug:none -mv7M3 --code_state=16 -me --include_path="C:/Users/Einstein/MyWorkspaceCC1350/adc_window_monitor_launchpad_tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/devices/cc13x0" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/kernel/tirtos" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source" --include_path="C:/ti/simplelink_cc13x0_sdk_2_30_00_20/source/ti/boards/CC1350_LAUNCHXL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --define=DEVICE_FAMILY=cc13x0 --define=DeviceFamily_CC13X0 -g --c99 --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3   -Dxdc_cfg__xheader__='"configPkg/package/cfg/rom_pem3.h"'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_16_9_8 -O2  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/rom_pem3.sem3: export C_DIR=
package/cfg/rom_pem3.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/;$(PATH)
package/cfg/rom_pem3.sem3: Path:=$(ti.targets.arm.elf.M3.rootDir)/bin/;$(PATH)

clean,em3 ::
	-$(RM) package/cfg/rom_pem3.oem3
	-$(RM) package/cfg/rom_pem3.sem3

rom.pem3: package/cfg/rom_pem3.oem3 package/cfg/rom_pem3.mak

clean::
	-$(RM) package/cfg/rom_pem3.mak
