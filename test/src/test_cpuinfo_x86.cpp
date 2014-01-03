#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>
#include <cpuid/commandline_arguments.hpp>

TEST(cpuinfo_x86_tests, check_instruction_sets)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    for(const auto& i : cpuid::variable_map) {

        bool result = false;

        if (i.first == std::string("has_fpu"))
        {
            result = m_cpuinfo.has_fpu();
        }
        else if (i.first == std::string("has_mmx"))
        {
            result = m_cpuinfo.has_mmx();
        }
        else if (i.first == std::string("has_sse"))
        {
            result = m_cpuinfo.has_sse();
        }
        else if (i.first == std::string("has_sse2"))
        {
            result = m_cpuinfo.has_sse2();
        }
        else if (i.first == std::string("has_sse3"))
        {
            result = m_cpuinfo.has_sse3();
        }
        else if (i.first == std::string("has_ssse3"))
        {
            result = m_cpuinfo.has_ssse3();
        }
        else if (i.first == std::string("has_sse4_1"))
        {
            result = m_cpuinfo.has_sse4_1();
        }
        else if (i.first == std::string("has_sse4_2"))
        {
            result = m_cpuinfo.has_sse4_2();
        }
        else if (i.first == std::string("has_pclmulqdq"))
        {
            result = m_cpuinfo.has_pclmulqdq();
        }
        else if (i.first == std::string("has_avx"))
        {
            result = m_cpuinfo.has_avx();
        }

        EXPECT_EQ(i.second.as<bool>(), result);
    }

}
