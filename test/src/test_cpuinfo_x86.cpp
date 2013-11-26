#include <cstdint>
#include <gtest/gtest.h>
#include <cpuid/cpuinfo_x86.hpp>

TEST(cpuninfo_x86_tests, basic_structure)
{
    cpuinfo_x86 m_cpuinfo;

    cpuinfo_x86.print_vendorID();
    cpuinfo_x86.print_EX_registers();

}
