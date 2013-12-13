#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>

TEST(cpuinfo_x86_tests, check_vendor_id)
{
    //Overloaded constructor
    cpuid::cpuinfo_x86 m_cpuinfo_vendor_features (0);
    EXPECT_EQ("GenuineIntel",m_cpuinfo_vendor_features.vendor_id());
}

TEST(cpuinfo_x86_tests, check_instruction_sets)
{
    //Default constructor
    cpuid::cpuinfo_x86 m_cpuinfo_instruction_features;

    EXPECT_TRUE(m_cpuinfo_instruction_features.has_fpu());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_mmx());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_sse());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_sse2());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_sse3());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_ssse3());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_sse4_1());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_sse4_2());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_pclmulqdq());
    EXPECT_TRUE(m_cpuinfo_instruction_features.has_avx());

}
