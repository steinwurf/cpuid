// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cpuid.h>

#include "cpuinfo.hpp"
#include "extract_x86_flags.hpp"

namespace cpuid
{
    /// @todo Document
    void init_cpuinfo(cpuinfo::impl& info)
    {
        // Note: We need to capture these 4 registers, otherwise we get
        // a segmentation fault on 32-bit Linux
        uint32_t eax = 0;
        uint32_t ebx = 0;
        uint32_t ecx = 0;
        uint32_t edx = 0;

        // Set registers for basic flag extraction
        __get_cpuid(1, &eax, &ebx, &ecx, &edx);
        extract_x86_flags(info, ecx, edx);

        // Set registers for extended flags extraction
        __get_cpuid(7, &eax, &ebx, &ecx, &edx);
        extract_x86_extended_flags(info, ebx);
    }
}
