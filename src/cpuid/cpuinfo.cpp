// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include "cpuinfo.hpp"
#include "config.hpp"
#include "cpuinfo_impl.hpp"

#if defined(CPUID_LINUX_GCC_X86)
    #include "init_linux_gcc_x86.hpp"
#elif defined(CPUID_LINUX_CLANG_X86)
    #include "init_linux_gcc_x86.hpp"
#elif defined(CPUID_LINUX_GCC_ARM)
    #include "init_linux_gcc_arm.hpp"
#elif defined(CPUID_LINUX_GCC_MIPS)
    #include "init_unknown.hpp"
#elif defined(CPUID_LINUX_CLANG_ARM)
    #include "init_linux_gcc_arm.hpp"
#elif defined(CPUID_ANDROID_GCC_ARM)
    #include "init_linux_gcc_arm.hpp"
#elif defined(CPUID_ANDROID_CLANG_ARM)
    #include "init_linux_gcc_arm.hpp"
#elif defined(CPUID_WIN32_MSVC_X86)
    #include "init_win32_msvc_x86.hpp"
#elif defined(CPUID_MAC_CLANG_X86)
    #include "init_linux_gcc_x86.hpp"
#elif defined(CPUID_MAC_GCC_X86)
    #include "init_linux_gcc_x86.hpp"
#elif defined(CPUID_IOS_CLANG_ARM)
    #include "init_ios_clang_arm.hpp"
#else
    #include "init_unknown.hpp"
#endif

namespace cpuid
{
    cpuinfo::cpuinfo() :
        m_impl(new impl)
    {
        init_cpuinfo(*m_impl);
    }

    cpuinfo::~cpuinfo()
    { }

    // x86 member functions
    bool cpuinfo::has_fpu() const
    {
        return m_impl->m_has_fpu;
    }

    bool cpuinfo::has_mmx() const
    {
        return m_impl->m_has_mmx;
    }

    bool cpuinfo::has_sse() const
    {
        return m_impl->m_has_sse;
    }

    bool cpuinfo::has_sse2() const
    {
        return m_impl->m_has_sse2;
    }

    bool cpuinfo::has_sse3() const
    {
        return m_impl->m_has_sse3;
    }

    bool cpuinfo::has_ssse3() const
    {
        return m_impl->m_has_ssse3;
    }

    bool cpuinfo::has_sse4_1() const
    {
        return m_impl->m_has_sse4_1;
    }

    bool cpuinfo::has_sse4_2() const
    {
        return m_impl->m_has_sse4_2;
    }

    bool cpuinfo::has_pclmulqdq() const
    {
        return m_impl->m_has_pclmulqdq;
    }

    bool cpuinfo::has_avx() const
    {
        return m_impl->m_has_avx;
    }

    // ARM functions
    bool cpuinfo::has_neon() const
    {
        return m_impl->m_has_neon;
    }

    std::string cpuinfo::platform() const
    {
        return CPUID_PLATFORM;
    }
}
