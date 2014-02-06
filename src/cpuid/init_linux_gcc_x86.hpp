// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "cpuinfo.hpp"
#include "extract_info.hpp"

namespace cpuid
{
    /// @todo Document
    void init_cpuinfo(cpuinfo::impl& info)
    {

        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        // Get vendor ID string

        invoke_cpuid(eax, ebx, ecx, edx, 0);
        extract_vendor_id(info, ebx, ecx, edx);

        // Get flags and logical cores count

        invoke_cpuid(eax, ebx, ecx, edx, 1);
        extract_x86_features(info, ebx, ecx, edx);

        // Get physical cores count (Vendor dependent)
        // Source: http://stackoverflow.com/questions/2901694

        if(info.m_vendor_id == "GenuineIntel")
        {
            invoke_cpuid(eax, ebx, ecx, edx, 4);
            info.m_physical_cores = ((eax >> 26) & 0x3f) + 1; // EAX[31:26] + 1
        }
        else if(info.m_vendor_id == "AuthenticAMD")
        {
            invoke_cpuid(eax, ebx, ecx, edx, 0x80000008);
            info.m_physical_cores = ((uint32_t)(ecx & 0xff)) + 1;// ECX[7:0] + 1
        }

    }

}
