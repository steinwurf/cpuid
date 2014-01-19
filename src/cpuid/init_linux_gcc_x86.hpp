// Copyright (c) 2011-2014 Steinwurf ApS
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

    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
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
                : "a"(1) );

        extract_x86_flags(info, ecx, edx);
    }

}
