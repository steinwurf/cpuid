#include <ctime>
#include <string>

#include <cpuid/cpuinfo_x86.hpp>


int main()
{
    cpuid::cpuinfo_x86 m_cpuid;

    std::cout << "CPU has FPU?: "
        << (m_cpuid.has_fpu() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has MMX?: "
        << (m_cpuid.has_mmx() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE?: "
        << (m_cpuid.has_sse() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE2?: "
        << (m_cpuid.has_sse2() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE3?: "
        << (m_cpuid.has_sse3() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSSE3?: "
        << (m_cpuid.has_ssse3() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE4.1?: "
        << (m_cpuid.has_sse4_1() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE4.2?: "
        << (m_cpuid.has_sse4_2() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has PCLMULQDQ?: "
        << (m_cpuid.has_pclmulqdq() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX?: "
        << (m_cpuid.has_avx() ? "Yes" : "No") << std::endl;

    return 0;
}

