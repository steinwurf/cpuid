// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include <cstdint>
#include "extract_vendor_id.hpp"

namespace cpuid
{

    /// @todo docs
    void cpuid_0_calls(cpuinfo::impl& info)
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
                : "a"(0) );

        extract_vendor_id(info, ebx, ecx, edx);
    }
}
