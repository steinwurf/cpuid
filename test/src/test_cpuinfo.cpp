// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <cpuid/cpuinfo.hpp>

#include <gtest/gtest.h>

#include <cstdint>
#include <iostream>
#include <map>

extern std::map<std::string, bool> variable_map;

TEST(cpuinfo_tests, check_instruction_sets)
{
    cpuid::cpuinfo m_cpuinfo;

    // Check CPU capabilities
    EXPECT_EQ(variable_map["has_fpu"], m_cpuinfo.has_fpu());
    EXPECT_EQ(variable_map["has_mmx"], m_cpuinfo.has_mmx());
    EXPECT_EQ(variable_map["has_sse"], m_cpuinfo.has_sse());
    EXPECT_EQ(variable_map["has_sse2"], m_cpuinfo.has_sse2());
    EXPECT_EQ(variable_map["has_sse3"], m_cpuinfo.has_sse3());
    EXPECT_EQ(variable_map["has_ssse3"], m_cpuinfo.has_ssse3());
    EXPECT_EQ(variable_map["has_sse4_1"], m_cpuinfo.has_sse4_1());
    EXPECT_EQ(variable_map["has_sse4_2"], m_cpuinfo.has_sse4_2());
    EXPECT_EQ(variable_map["has_pclmulqdq"], m_cpuinfo.has_pclmulqdq());
    EXPECT_EQ(variable_map["has_avx"], m_cpuinfo.has_avx());
    EXPECT_EQ(variable_map["has_avx2"], m_cpuinfo.has_avx2());
    EXPECT_EQ(variable_map["has_avx512_f"], m_cpuinfo.has_avx512_f());
    EXPECT_EQ(variable_map["has_avx512_dq"], m_cpuinfo.has_avx512_dq());
    EXPECT_EQ(variable_map["has_avx512_ifma"], m_cpuinfo.has_avx512_ifma());
    EXPECT_EQ(variable_map["has_avx512_pf"], m_cpuinfo.has_avx512_pf());
    EXPECT_EQ(variable_map["has_avx512_er"], m_cpuinfo.has_avx512_er());
    EXPECT_EQ(variable_map["has_avx512_cd"], m_cpuinfo.has_avx512_cd());
    EXPECT_EQ(variable_map["has_avx512_bw"], m_cpuinfo.has_avx512_bw());
    EXPECT_EQ(variable_map["has_avx512_vl"], m_cpuinfo.has_avx512_vl());
    EXPECT_EQ(variable_map["has_avx512_vbmi"], m_cpuinfo.has_avx512_vbmi());
    EXPECT_EQ(variable_map["has_avx512_vbmi2"], m_cpuinfo.has_avx512_vbmi2());
    EXPECT_EQ(variable_map["has_avx512_vnni"], m_cpuinfo.has_avx512_vnni());
    EXPECT_EQ(variable_map["has_avx512_bitalg"], m_cpuinfo.has_avx512_bitalg());
    EXPECT_EQ(variable_map["has_avx512_vpopcntdq"],
              m_cpuinfo.has_avx512_vpopcntdq());
    EXPECT_EQ(variable_map["has_avx512_4vnniw"], m_cpuinfo.has_avx512_4vnniw());
    EXPECT_EQ(variable_map["has_avx512_4fmaps"], m_cpuinfo.has_avx512_4fmaps());
    EXPECT_EQ(variable_map["has_avx512_vp2intersect"],
              m_cpuinfo.has_avx512_vp2intersect());
    EXPECT_EQ(variable_map["has_f16c"], m_cpuinfo.has_f16c());
    EXPECT_EQ(variable_map["has_aes"], m_cpuinfo.has_aes());
    EXPECT_EQ(variable_map["has_neon"], m_cpuinfo.has_neon());
}
