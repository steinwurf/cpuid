// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <iostream>

#include <cpuid/cpuinfo.hpp>

int main()
{
    cpuid::cpuinfo m_cpuid;

    std::cout << "CPU has FPU?: " << (m_cpuid.has_fpu() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has MMX?: " << (m_cpuid.has_mmx() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSE?: " << (m_cpuid.has_sse() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSE2?: " << (m_cpuid.has_sse2() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSE3?: " << (m_cpuid.has_sse3() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSSE3?: " << (m_cpuid.has_ssse3() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSE4.1?: " << (m_cpuid.has_sse4_1() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has SSE4.2?: " << (m_cpuid.has_sse4_2() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has PCLMULQDQ?: "
              << (m_cpuid.has_pclmulqdq() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX?: " << (m_cpuid.has_avx() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has AVX2?: " << (m_cpuid.has_avx2() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has AVX512F?: " << (m_cpuid.has_avx512_f() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has AVX512DQ?: "
              << (m_cpuid.has_avx512_dq() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512IFMA?: "
              << (m_cpuid.has_avx512_ifma() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512PF?: "
              << (m_cpuid.has_avx512_pf() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512ER?: "
              << (m_cpuid.has_avx512_er() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512CD?: "
              << (m_cpuid.has_avx512_cd() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512BW?: "
              << (m_cpuid.has_avx512_bw() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VL?: "
              << (m_cpuid.has_avx512_vl() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VBMI?: "
              << (m_cpuid.has_avx512_vbmi() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VBMI2?: "
              << (m_cpuid.has_avx512_vbmi2() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VNNI?: "
              << (m_cpuid.has_avx512_vnni() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512BITALG?: "
              << (m_cpuid.has_avx512_bitalg() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VPOPCNTDQ?: "
              << (m_cpuid.has_avx512_vpopcntdq() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX5124VNNIW?: "
              << (m_cpuid.has_avx512_4vnniw() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX5124FMAPS?: "
              << (m_cpuid.has_avx512_4fmaps() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX512VP2INTERSECT?: "
              << (m_cpuid.has_avx512_vp2intersect() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has F16C?: " << (m_cpuid.has_f16c() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has AES?: " << (m_cpuid.has_aes() ? "Yes" : "No")
              << std::endl;

    std::cout << "CPU has ARM NEON?: " << (m_cpuid.has_neon() ? "Yes" : "No")
              << std::endl;

    return 0;
}
