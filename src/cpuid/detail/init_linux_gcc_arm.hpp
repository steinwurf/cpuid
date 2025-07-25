// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cassert>
#include <cstdio>
#include <cstring>

#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

// The following includes are needed for the runtime detection of NEON
#ifdef PLATFORM_FREEBSD
// FreeBSD uses sys/auxv.h
#include <sys/auxv.h>
#else
// Linux uses linux/auxvec.h
#include <linux/auxvec.h>
#endif

#include "cpuinfo_impl.hpp"

namespace cpuid
{
inline namespace STEINWURF_CPUID_VERSION
{
/// @todo docs
void init_cpuinfo(cpuinfo::impl& info)
{
#if defined(__aarch64__)
    // The Advanced SIMD (NEON) instruction set is required on AArch64
    // (64-bit ARM). Note that /proc/cpuinfo will display "asimd" instead of
    // "neon" in the Features list on a 64-bit ARM CPU.
    info.m_has_neon = true;
#else
    // Runtime detection of NEON is necessary on 32-bit ARM CPUs

#ifdef PLATFORM_FREEBSD
    // On FreeBSD we use the elf_aux_info function to get the HWCAP
    long hwcap = 0;
    elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
    info.m_has_neon = hwcap & HWCAP_NEON;
#else
    // Follow recommendation from Cortex-A Series Programmer's guide
    // in Section 20.1.7 Detecting NEON. The guide is available at
    // Steinwurf's Google drive: steinwurf/technical/experimental/cpuid
    auto cpufile = open("/proc/self/auxv", O_RDONLY);
    assert(cpufile);

    Elf32_auxv_t auxv;

    if (cpufile >= 0)
    {
        const auto size_auxv_t = sizeof(Elf32_auxv_t);
        while (read(cpufile, &auxv, size_auxv_t) == size_auxv_t)
        {
            if (auxv.a_type == AT_HWCAP)
            {
                info.m_has_neon = (auxv.a_un.a_val & 4096) != 0;
                break;
            }
        }

        close(cpufile);
    }
    else
    {
        info.m_has_neon = false;
    }
#endif
#endif
}
}
}
