/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

static const variant_info_t vayu_info = {
    .hwc_value = "GLOBAL",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .mod_device = "vayu_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = "POCO/vayu_global/vayu:11/RKQ1.200826.002/V12.0.4.0.RJUMIXM:user/release-keys",

    .nfc = true,
};

static const variant_info_t bhima_info = {
    .hwc_value = "INDIA",
    .sku_value = "",

    .brand = "POCO",
    .device = "bhima",
    .mod_device = "bhima_in",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SI",
    .build_fingerprint = "POCO/bhima_in/bhima:11/RKQ1.200826.002/V12.0.4.0.RJUINXM:user/release-keys",

    .nfc = false,
};

static const std::vector<variant_info_t> variants = {
    vayu_info,
    bhima_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    #ifndef __ANDROID_RECOVERY__
    search_variant(variants);
    #endif
}
