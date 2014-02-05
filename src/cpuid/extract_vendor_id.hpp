// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include <cstdint>

namespace cpuid
{

    /// @todo docs
    void extract_vendor_id(cpuinfo::impl& info)
    {
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        __asm__("cpuid"
                : "=b"(ebx), "=c"(ecx), "=d"(edx)
                : "a"(0)
                : "eax" );

        // Get vendor ID

        std::string vendor_id;

        vendor_id += std::string((const char *)&ebx, 4);
        vendor_id += std::string((const char *)&edx, 4);
        vendor_id += std::string((const char *)&ecx, 4);


        info.m_vendor_id = vendor_id;
    }
}
