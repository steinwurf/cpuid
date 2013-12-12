#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>

TEST(cpuinfo_x86_tests, basic_commands)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    uint8_t eax_input = 0;

    m_cpuinfo.get_cpuinfo(eax_input);
    m_cpuinfo.print_vendor_id();
    m_cpuinfo.print_EX_registers(eax_input);

    eax_input = 1;
    m_cpuinfo.get_cpuinfo(eax_input);
    m_cpuinfo.print_EX_registers(eax_input);

    bool has_FPU = m_cpuinfo.has_instruction_set("FPU");
    bool has_MMX = m_cpuinfo.has_instruction_set("MMX");
    bool has_SSE = m_cpuinfo.has_instruction_set("SSE");
    bool has_SSE2 = m_cpuinfo.has_instruction_set("SSE2");
    bool has_SSE3 = m_cpuinfo.has_instruction_set("SSE3");
    bool has_SSSE3 = m_cpuinfo.has_instruction_set("SSSE3");
    bool has_SSE4_1 = m_cpuinfo.has_instruction_set("SSE4.1");
    bool has_SSE4_2 = m_cpuinfo.has_instruction_set("SSE4.2");
    bool has_PCLMULQDQ = m_cpuinfo.has_instruction_set("PCLMULQDQ");
    bool has_AVX = m_cpuinfo.has_instruction_set("AVX");


    EXPECT_TRUE(has_FPU);
    EXPECT_TRUE(has_MMX);
    EXPECT_TRUE(has_SSE);
    EXPECT_TRUE(has_SSE2);
    EXPECT_TRUE(has_SSE3);
    EXPECT_TRUE(has_SSSE3);
    EXPECT_TRUE(has_SSE4_1);
    EXPECT_TRUE(has_SSE4_2);
    EXPECT_TRUE(has_PCLMULQDQ);
    EXPECT_TRUE(has_AVX);

}
