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
    void extract_x86_flags(cpuinfo::impl& info, uint32_t ecx, uint32_t edx)
    {
        info.m_has_fpu = bool(edx & (1 << 0));
        info.m_has_mmx = bool(edx & (1 << 23));
        info.m_has_sse = bool(edx & (1 << 25));
        info.m_has_sse2 = bool(edx & (1 << 26));
        info.m_has_sse3 = bool(ecx & (1 << 0));
        info.m_has_ssse3 = bool(ecx & (1 << 9));
        info.m_has_sse4_1 = bool(ecx & (1 << 19));
        info.m_has_sse4_2 = bool(ecx & (1 << 20));
        info.m_has_pclmulqdq = bool(ecx & (1 << 1));
        info.m_has_avx = bool(ecx & (1 << 28));
    }
}
