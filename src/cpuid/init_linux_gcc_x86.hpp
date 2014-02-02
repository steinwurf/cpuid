// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "cpuinfo.hpp"
#include "cpuid_0_calls.hpp"
#include "cpuid_1_calls.hpp"
#include "cpuid_4_calls.hpp"
#include "cpuid_80000008_calls.hpp"

namespace cpuid
{

    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
    {

        // Get vendor ID string
        cpuid_0_calls(info);

        // Get flags and logical cores count
        cpuid_1_calls(info);

        // Get physical cores count (Vendor dependent)
        if(info.m_vendor_id == "GenuineIntel")
        {
            cpuid_4_calls(info);
        }
        else if(info.m_vendor_id == "AuthenticAMD")
        {
            cpuid_80000008_calls(info);
        }

    }

}
