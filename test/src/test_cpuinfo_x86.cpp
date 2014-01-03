#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>
#include <cpuid/commandline_arguments.hpp>

TEST(cpuinfo_x86_tests, check_instruction_sets)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    for(auto& i : cpuid::variable_map) {

        bool result = false;

        if (i.first == std::string("has_fpu"))
        {
            result = m_cpuinfo.has_fpu();
        }
        else if (i.first == std::string("has_mmx"))
        {
            result = m_cpuinfo.has_mmx();
        }

        EXPECT_EQ(i.second.as<bool>(), result);
    }

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
