// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

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
