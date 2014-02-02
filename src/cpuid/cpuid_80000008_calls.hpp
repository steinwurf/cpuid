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
    void cpuid_80000008_calls(cpuinfo::impl& info)
    {
        /// @todo why do we get all the registers when we
        ///       only use ecx and edx?
        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        __asm__("cpuid"
                : "=a"(eax), "=b"(ebx),
                  "=c"(ecx), "=d"(edx)
                : "a"(0x80000008), "c"(0) );

        // Get physical core count for AMD according to
        // http://stackoverflow.com/questions/2901694/
        info.m_physical_cores = ((uint32_t)(ecx & 0xff)) + 1; // ECX[7:0] + 1
    }
}
