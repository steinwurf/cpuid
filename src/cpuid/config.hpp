// Copyright (c) 2011-2014 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

// There exists no inter-compiler standard for the preprocessed
// defines, here we create a number of defines to make it easy in the
// cpuid implementation to choose between different
// implementations. The defines used can be found here:
// http://sourceforge.net/p/predef/wiki/Architectures/

#if defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
    #define CPUID_GCC_X86 1
#elif defined(__clang__) && (defined(__i386__) || defined(__x86_64__))
    #define CPUID_CLANG_X86 1
#elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
    #define CPUID_MSVC_X86 1
#else
    #define CPUID_UNKNOWN 1
#endif

