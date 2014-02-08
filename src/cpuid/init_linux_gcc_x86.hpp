// Copyright (c) 2011-2014 Steinwurf ApS:w

// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "cpuinfo.hpp"
#include "extract_x86_flags.hpp"

namespace cpuid
{
    /// @todo Document
    void init_cpuinfo(cpuinfo::impl& info)
    {
        // Note: We need to capture these 4 registers, otherwise we get
        // a segmentation fault on 32-bit Linux
        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        __asm__("cpuid"
                : "=a"(eax), "=b"(ebx),
                  "=c"(ecx), "=d"(edx)
                : "a"(1) );

        // Get flags
        extract_x86_flags(info, ecx, edx);
    }
}
