// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include <intrin.h>

#include "cpuinfo.hpp"
#include "extract_info.hpp"

namespace cpuid
{
    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
    {
        int registers[4];

        /// According to the msvc docs eax, ebx, ecx and edx are
        /// stored (in that order) in the array passed to the __cpuid
        /// function.

        // Get vendor ID string

        __cpuid(registers, 0);
        extract_vendor_id(info, registers[1], registers[2], registers[3]);

        // Get flags and logical cores count

        __cpuid(registers, 1);
        extract_x86_features(info, registers[1], registers[2], registers[3]);

        // Get physical cores count (Vendor dependent)
        // Source: http://stackoverflow.com/questions/2901694

        if (info.m_vendor_id == "GenuineIntel")
        {
            __cpuid(registers, 4);
            info.m_physical_cores = ((registers[0] >> 26) & 0x3f) + 1;
            // EAX[31:26] + 1
        }
        else if (info.m_vendor_id == "AuthenticAMD")
        {
            __cpuid(registers, 0x80000008);
            info.m_physical_cores = ((uint32_t)(registers[2] & 0xff)) + 1;
            // ECX[7:0] + 1
        }
    }
}
