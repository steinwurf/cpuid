// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See accompanying file LICENSE.rst

#pragma once

#include "cpuinfo.hpp"

namespace cpuid
{

    /// @todo docs
    void init_cpuinfo(cpuinfo::impl& info)
    {
        // The __ARM_NEON__ macro will be defined by the Apple LLVM compiler
        // when targeting ARMv7 processors that have NEON.
        // The compiler guarantees this capability, so there is no benefit
        // in doing a runtime check. More info in this SO answer:
        // http://stackoverflow.com/a/1601234

#if defined __ARM_NEON__
        info.m_has_neon = true;
#else
        info.m_has_neon = false;
#endif
    }

}
