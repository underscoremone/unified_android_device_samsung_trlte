#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common trlte
-include device/samsung/trlte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := trlte,trltedt,trltecan,trltespr,trltetmo,trlteusc,trltevzw,trltexx

# Camera
TARGET_FIXUP_PREVIEW := true

# Init
TARGET_INIT_VENDOR_LIB := libinit_trlte
TARGET_UNIFIED_DEVICE := true

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := device/samsung/trlte-common/releasetools

# inherit from the proprietary version
-include vendor/samsung/trlte/BoardConfigVendor.mk
