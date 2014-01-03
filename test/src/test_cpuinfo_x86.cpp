#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>
#include "../commandline_arguments.hpp"

TEST(cpuinfo_x86_tests, check_instruction_sets)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    EXPECT_EQ(variable_map["has_fpu"].as<bool>(), m_cpuinfo.has_fpu());
    EXPECT_EQ(variable_map["has_mmx"].as<bool>(), m_cpuinfo.has_mmx());
    EXPECT_EQ(variable_map["has_sse"].as<bool>(), m_cpuinfo.has_sse());
    EXPECT_EQ(variable_map["has_sse2"].as<bool>(), m_cpuinfo.has_sse2());
    EXPECT_EQ(variable_map["has_sse3"].as<bool>(), m_cpuinfo.has_sse3());
    EXPECT_EQ(variable_map["has_ssse3"].as<bool>(), m_cpuinfo.has_ssse3());
    EXPECT_EQ(variable_map["has_sse4_1"].as<bool>(), m_cpuinfo.has_sse4_1());
    EXPECT_EQ(variable_map["has_sse4_2"].as<bool>(), m_cpuinfo.has_sse4_2());
    EXPECT_EQ(variable_map["has_pclmulqdq"].as<bool>(),
              m_cpuinfo.has_pclmulqdq());
    EXPECT_EQ(variable_map["has_avx"].as<bool>(), m_cpuinfo.has_avx());

}
