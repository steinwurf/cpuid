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

#include <iostream>
#include "cpuinfo.hpp"

namespace cpuid
{

    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
    {
        auto cpufile = fopen("/proc/cpuinfo","r");
        assert(cpufile);

        char buffer[512];
        std::string str(buffer);

        std::cout << str << "\n";

        while(fgets(buffer, 511, cpufile))
        {


            if(memcmp(buffer, "Features", 8) == 0)
            {
                char* neon = strstr(buffer, "neon");
                info.m_has_neon = neon != 0;
            }
            else
            {
                info.m_has_neon = false;
            }
        }

        fclose(cpufile);
    }

}
