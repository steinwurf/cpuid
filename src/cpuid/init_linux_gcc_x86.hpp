// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "cpuinfo.hpp"

namespace cpuid
{

    void invoke_cpuid(uint32_t& eax, uint32_t& ebx,
                      uint32_t& ecx, uint32_t& edx,
                      uint32_t input)
    {
        __asm__("cpuid"
                : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                : "a"(input));
    }

    void extract_vendor_id(cpuinfo::impl& info,
                           uint32_t ebx, uint32_t ecx, uint32_t edx)
    {

        std::string vendor_id;

        vendor_id += std::string((const char *)&ebx, 4);
        vendor_id += std::string((const char *)&edx, 4);
        vendor_id += std::string((const char *)&ecx, 4);

        info.m_vendor_id = vendor_id;
    }

    void extract_x86_info(cpuinfo::impl& info,
                          uint32_t ebx, uint32_t ecx, uint32_t edx)
    {

        info.m_has_fpu = (edx & (1 << 0)) != 0;
        info.m_has_mmx = (edx & (1 << 23)) != 0;
        info.m_has_sse = (edx & (1 << 25)) != 0;
        info.m_has_sse2 = (edx & (1 << 26)) != 0;
        info.m_has_sse3 = (ecx & (1 << 0)) != 0;
        info.m_has_ssse3 = (ecx & (1 << 9)) != 0;
        info.m_has_sse4_1 = (ecx & (1 << 19)) != 0;
        info.m_has_sse4_2 = (ecx & (1 << 20)) != 0;
        info.m_has_pclmulqdq = (ecx & (1 << 1)) != 0;
        info.m_has_avx = (ecx & (1 << 28)) != 0;

        // Check the logical core count from EBX[23:16]
        // Source: http://stackoverflow.com/questions/2901694
        info.m_logical_cores = (ebx >> 16) & 0xff;

    }


    void extract_x86_physical_cores(cpuinfo::impl& info,
                                    uint32_t eax, uint32_t ecx)
    {
        // Get physical core count for AMD according to
        // http://stackoverflow.com/questions/2901694/

        if(info.m_vendor_id == "GenuineIntel")
        {
            invoke_cpuid(eax,0,0,0,4);
            info.m_physical_cores = ((eax >> 26) & 0x3f) + 1; // EAX[31:26] + 1
        }
        else if(info.m_vendor_id == "AuthenticAMD")
        {
            invoke_cpuid(0,0,ecx,0,0x80000008);
            info.m_physical_cores = ((uint32_t)(ecx & 0xff)) + 1;// ECX[7:0] + 1
        }

    }

    /// @todo Document
    void init_cpuinfo(cpuinfo::impl& info)
    {

        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        // Get vendor ID string
        invoke_cpuid(0,ebx,ecx,edx,0);
        extract_vendor_id(info,ebx,ecx,edx);

        // Get flags and logical cores count
        invoke_cpuid(0,ebx,ecx,edx,1);
        extract_x86_info(info,ebx,ecx,edx);

        // Get physical cores count (Vendor dependent)
        extract_x86_physical_cores(info,eax,ecx);

    }

}
