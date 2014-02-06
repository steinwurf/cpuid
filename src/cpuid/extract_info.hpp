// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

namespace cpuid
{

    void extract_vendor_id(cpuinfo::impl& info,
                           uint32_t ebx, uint32_t ecx, uint32_t edx)
    {

        std::string vendor_id;

        vendor_id += std::string((const char *)&ebx, 4);
        vendor_id += std::string((const char *)&edx, 4);
        vendor_id += std::string((const char *)&ecx, 4);

        info.m_vendor_id = vendor_id;
    }

    void extract_x86_features(cpuinfo::impl& info,
                              uint32_t ebx, uint32_t ecx, uint32_t edx)
    {

        // Instruction set flags

        info.m_has_fpu = (edx & (1 << 0)) != 0;
        info.m_has_mmx = (edx & (1 << 23)) != 0;
        info.m_has_sse = (edx & (1 << 25)) != 0;
        info.m_has_sse2 = (edx & (1 << 26)) != 0;
        info.m_has_sse3 = (ecx & (1 << 0)) != 0;
        info.m_has_ssse3 = (ecx & (1 << 9)) != 0;
        info.m_has_sse4_1 = (ecx & (1 << 19)) != 0;
        info.m_has_sse4_2 = (ecx & (1 << 20)) != 0;
        info.m_has_pclmulqdq = (ecx & (1 << 1)) != 0;
        info.m_has_avx = (ecx & (1 << 28)) != 0;

        // Check the logical core count from EBX[23:16]
        // Source: http://stackoverflow.com/questions/2901694

        info.m_logical_cores = (ebx >> 16) & 0xff;

    }
}
