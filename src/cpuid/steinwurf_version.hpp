// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <string>

namespace cpuid
{
    /// Returns a string representing the Steinwurf version of this library.
    inline std::string steinwurf_version()
    {
        #ifdef STEINWURF_CPUID_VERSION
        return STEINWURF_CPUID_VERSION;
        #else
        return "unknown";
        #endif
    }
}
