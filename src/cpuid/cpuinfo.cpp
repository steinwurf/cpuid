// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

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
#elif defined(CPUID_MAC_LLVM_X86)
    #include "init_mac_llvm_x86.hpp"
#elif defined(CPUID_MAC_GCC_X86)
    #include "init_linux_gcc_x86.hpp"
#else
    #include "init_unknown.hpp"
#endif

namespace cpuid
{

    cpuinfo::cpuinfo()
        : m_impl(new impl)
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

    bool cpuinfo::has_neon() const
    {
        return m_impl->m_has_neon;
    }

    std::string cpuinfo::platform() const
    {
        return CPUID_PLATFORM;
    }

}
