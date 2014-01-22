// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include <cstdio>
#include <cassert>
#include <cstring>

#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <linux/auxvec.h>

#include "cpuinfo.hpp"

namespace cpuid
{

    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
    {
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
                    info.m_has_neon = (auxv.a_un.a_val & 4096) ? true : false;
                    break;
                }
            }

            close (cpufile);
        }
        else
        {
            info.m_has_neon = false;
        }

    }

}
