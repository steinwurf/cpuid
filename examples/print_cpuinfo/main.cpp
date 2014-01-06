#include <ctime>
#include <string>

#include <cpuid/cpuinfo_x86.hpp>


int main()
{
    srand((uint32_t)time(0));

    cpuid::cpuinfo_x86 m_cpuid;

    printf("CPU has FPU?: %s \n", m_cpuid.has_fpu() ? "Yes" : "No");
    printf("CPU has MMX?: %s \n", m_cpuid.has_mmx() ? "Yes" : "No");
    printf("CPU has SSE?: %s \n", m_cpuid.has_sse() ? "Yes" : "No");
    printf("CPU has SSE2?: %s \n", m_cpuid.has_sse2() ? "Yes" : "No");
    printf("CPU has SSE3?: %s \n", m_cpuid.has_sse3() ? "Yes" : "No");
    printf("CPU has SSSE3?: %s \n", m_cpuid.has_ssse3() ? "Yes" : "No");
    printf("CPU has SSE4.1?: %s \n", m_cpuid.has_sse4_1() ? "Yes" : "No");
    printf("CPU has SSE4.2?: %s \n", m_cpuid.has_sse4_2() ? "Yes" : "No");
    printf("CPU has PCLMULQDQ?: %s \n", m_cpuid.has_pclmulqdq() ? "Yes" : "No");
    printf("CPU has AVX?: %s \n", m_cpuid.has_avx() ? "Yes" : "No");

    return 0;
}

