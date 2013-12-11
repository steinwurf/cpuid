#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>

TEST(cpuninfo_x86_tests, basic_commands)
{
    cpuid::cpuinfo_x86 m_cpuinfo;

    int eax_input = 0;

    m_cpuinfo.get_cpuinfo(eax_input);
    m_cpuinfo.print_vendor_id();
    m_cpuinfo.print_EX_registers(eax_input);

}
