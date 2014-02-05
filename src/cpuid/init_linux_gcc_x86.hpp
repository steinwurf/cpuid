// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "cpuinfo.hpp"
//#include "cpuid_0_calls.hpp"
#include "cpuid_1_calls.hpp"
#include "cpuid_4_calls.hpp"
#include "cpuid_80000008_calls.hpp"

namespace cpuid
{

    void extract_vendor_id(cpuinfo::impl& info)
    {
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        __asm__("cpuid"
                : "=b"(ebx), "=c"(ecx), "=d"(edx)
                : "a"(0));

        std::string vendor_id;

        vendor_id += std::string((const char *)&ebx, 4);
        vendor_id += std::string((const char *)&edx, 4);
        vendor_id += std::string((const char *)&ecx, 4);

        info.m_vendor_id = vendor_id;
    }

    /// @todo Document
    void init_cpuinfo(cpuinfo::impl& info)
    {

        // Get vendor ID string
        extract_vendor_id(info);

        // Get flags and logical cores count
        cpuid_1_calls(info);

        // Get physical cores count (Vendor dependent)
        if(info.m_vendor_id == "GenuineIntel")
        {
            cpuid_4_calls(info);
        }
        else if(info.m_vendor_id == "AuthenticAMD")
        {
            cpuid_80000008_calls(info);
        }

    }

}
