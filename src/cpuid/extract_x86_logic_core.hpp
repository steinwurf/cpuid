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
    void extract_x86_logic_core(cpuinfo::impl& info, uint32_t ebx)
    {
        // Check the logical core count from EBX[23:16] and when cpuid input is
        // "1". Source: http://stackoverflow.com/questions/2901694
        info.m_logical_cores = (ebx >> 16) & 0xff;
    }
}
