// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once
#include "cpuinfo.hpp"

namespace cpuid
{

    struct cpuinfo::impl
    {
        impl() :
            m_has_fpu(false),
            m_has_mmx(false),
            m_has_sse(false),
            m_has_sse2(false),
            m_has_sse3(false),
            m_has_ssse3(false),
            m_has_sse4_1(false),
            m_has_sse4_2(false),
            m_has_pclmulqdq(false),
            m_has_avx(false),
            m_has_neon(false),
            m_vendor_id(""),
            m_physical_cores(1),
            m_logical_cores(1)
        { }

        bool m_has_fpu;
        bool m_has_mmx;
        bool m_has_sse;
        bool m_has_sse2;
        bool m_has_sse3;
        bool m_has_ssse3;
        bool m_has_sse4_1;
        bool m_has_sse4_2;
        bool m_has_pclmulqdq;
        bool m_has_avx;
        bool m_has_neon;

        std::string m_vendor_id;

        uint32_t m_physical_cores;
        uint32_t m_logical_cores;

    };

}
