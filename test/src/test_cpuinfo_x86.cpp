#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>

TEST(cpuinfo_x86_tests, check_instruction_sets)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    EXPECT_TRUE(m_cpuinfo.has_fpu());
    EXPECT_TRUE(m_cpuinfo.has_mmx());
    EXPECT_TRUE(m_cpuinfo.has_sse());
    EXPECT_TRUE(m_cpuinfo.has_sse2());
    EXPECT_TRUE(m_cpuinfo.has_sse3());
    EXPECT_TRUE(m_cpuinfo.has_ssse3());
    EXPECT_TRUE(m_cpuinfo.has_sse4_1());
    EXPECT_TRUE(m_cpuinfo.has_sse4_2());
    EXPECT_TRUE(m_cpuinfo.has_pclmulqdq());
    EXPECT_TRUE(m_cpuinfo.has_avx());

}
