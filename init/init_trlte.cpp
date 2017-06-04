/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"
#include <sys/system_properties.h>

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void cdma_properties(char const *operator_alpha,
                     char const *operator_numeric,
                     char const *cdma_sub)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_cdma_sub", cdma_sub);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.telephony.default_network", "10");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_variant_properties() {
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader, NULL);

    if (strstr(bootloader, "N910F")) {
        /* trltexx */
        property_set("ro.build.fingerprint", "samsung/trltexx/trlte:6.0.1/MMB29M/N910FXXS1DQE1:user/release-keys");
        property_set("ro.build.description", "trltexx-user 6.0.1 MMB29M N910FXXS1DQE1 release-keys");
        property_set("ro.product.model", "SM-N910F");
        property_set("ro.product.device", "trltexx");
        gsm_properties();
    } else if (strstr(bootloader, "N910G")) {
        /* trltedt */
        property_set("ro.build.fingerprint", "samsung/trltedt/trlte:6.0.1/MMB29M/N910GDTS1DQE1:user/release-keys");
        property_set("ro.build.description", "trltedt-user 6.0.1 MMB29M N910GDTS1DQE1 release-keys");
        property_set("ro.product.model", "SM-N910G");
        property_set("ro.product.device", "trltedt");
        gsm_properties();
    } else if (strstr(bootloader, "N910R4")) {
        /* trlteusc */
        property_set("ro.build.fingerprint", "samsung/trlteusc/trlte:6.0.1/MMB29M/N910R4TYS1CQC1:user/release-keys");
        property_set("ro.build.description", "trlteusc-user 6.0.1 MMB29M N910R4TYS1CQC1 release-keys");
        property_set("ro.product.model", "SM-N910R4");
        property_set("ro.product.device", "trlteusc");
        cdma_properties("U.S. Cellular", "311580", "0");
    } else if (strstr(bootloader, "N910P")) {
        /* trltespr */
        property_set("ro.build.fingerprint", "samsung/trltespr/trlte:6.0.1/MMB29M/N910PVPS4DQC1:user/release-keys");
        property_set("ro.build.description", "trltespr-user 6.0.1 MMB29M N910PVPS4DQC1 release-keys");
        property_set("ro.product.model", "SM-N910P");
        property_set("ro.product.device", "trltespr");
        cdma_properties("Sprint", "310120", "1");
    } else if (strstr(bootloader, "N910T")) {
        /* trltetmo */
        property_set("ro.build.fingerprint", "samsung/trltetmo/trlte:6.0.1/MMB29M/N910TUVS2EQE2:user/release-keys");
        property_set("ro.build.description", "trltetmo-user 6.0.1 MMB29M N910TUVS2EQE2 release-keys");
        property_set("ro.product.model", "SM-N910T");
        property_set("ro.product.device", "trltetmo");
        gsm_properties();
    } else if (strstr(bootloader, "N910V")) {
        /* trltevzw */
        property_set("ro.build.fingerprint", "samsung/trltevzw/trlte:6.0.1/MMB29M/N910VVRS2CQE1:user/release-keys");
        property_set("ro.build.description", "trltevzw-user 6.0.1 MMB29M N910VVRS2CQE1 release-keys");
        property_set("ro.product.model", "SM-N910V");
        property_set("ro.product.device", "trltevzw");
        cdma_properties("Verizon", "311480", "0");
    } else if (strstr(bootloader, "N910W8")) {
        /* trltecan */
        property_set("ro.build.fingerprint", "samsung/trltecan/trlte:6.0.1/MMB29M/N910W8VLS1DQD1:user/release-keys");
        property_set("ro.build.description", "trltecan-user 6.0.1 MMB29M N910W8VLS1DQD1 release-keys");
        property_set("ro.product.model", "SM-N910W8");
        property_set("ro.product.device", "trltecan");
        gsm_properties();
    } else {
        INFO("%s: unexcepted bootloader id!\n", bootloader, devicename);
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
}

void vendor_load_properties() {
    init_variant_properties();
}
