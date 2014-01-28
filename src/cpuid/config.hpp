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

/// First we differentiate between operating systems
#if defined(__linux__) && !defined(__ANDROID__)
    #define CPUID_LINUX
#elif defined(__linux__) && defined(__ANDROID__)
    #define CPUID_ANDROID
#elif defined(_WIN32)
    #define CPUID_WIN32
#elif defined(__APPLE__)
    // Detect iOS before MacOSX (__MACH__ is also defined for iOS)
    #if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE != 0)
        #pragma message "CPUID_IOS"
        #define CPUID_IOS
    #elif defined (__MACH__)
        #pragma message "CPUID_MAC"
        #define CPUID_MAC
    #endif
#else
    #error "Unable to determine operating system"
#endif

// Then we differentiate between compilers
#if defined(CPUID_LINUX)
    #if defined(__GNUC__)
        #define CPUID_LINUX_GCC
    #elif defined(__clang__)
        #define CPUID_LINUX_CLANG
    #endif
#elif defined(CPUID_ANDROID)
    #if defined(__GNUC__)
        #define CPUID_ANDROID_GCC
    #elif defined(__clang__)
        #define CPUID_ANDROID_CLANG
    #endif
#elif defined(CPUID_WIN32)
    #if defined(_MSC_VER)
        #define CPUID_WIN32_MSVC
    #endif
#elif defined(CPUID_MAC)
    #if defined(__llvm__)
        #define CPUID_MAC_LLVM
    #elif defined(__GNUC__)
        #define CPUID_MAC_GCC
    #endif
#elif defined(CPUID_IOS)
    #if defined(__llvm__)
        #pragma message "CPUID_IOS_LLVM"
        #define CPUID_IOS_LLVM
    #endif
#endif

// Then we differentiate between architectures
#if defined(CPUID_LINUX_GCC)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_LINUX_GCC_X86
        #define CPUID_PLATFORM "linux_gcc_x86"
    #elif defined(__arm__)
        #define CPUID_LINUX_GCC_ARM
        #define CPUID_PLATFORM "linux_gcc_arm"
    #elif defined(__mips__)
        #define CPUID_LINUX_GCC_MIPS
        #define CPUID_PLATFORM "linux_gcc_mips"
    #endif
#elif defined(CPUID_LINUX_CLANG)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_LINUX_CLANG_X86
        #define CPUID_PLATFORM "linux_clang_x86"
    #elif defined(__arm__)
        #define CPUID_LINUX_CLANG_ARM
        #define CPUID_PLATFORM "linux_clang_arm"
    #endif
#elif defined(CPUID_ANDROID_GCC)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_ANDROID_GCC_X86
        #define CPUID_PLATFORM "android_gcc_x86"
    #elif defined(__arm__)
        #define CPUID_ANDROID_GCC_ARM
        #define CPUID_PLATFORM "android_gcc_arm"
    #endif
#elif defined(CPUID_ANDROID_CLANG)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_ANDROID_CLANG_X86
        #define CPUID_PLATFORM "android_clang_x86"
    #elif defined(__arm__)
        #define CPUID_LINUX_CLANG_ARM
        #define CPUID_PLATFORM "android_clang_arm"
    #endif
#elif defined(CPUID_WIN32_MSVC)
    #if defined(_M_IX86) || defined(_M_X64)
        #define CPUID_WIN32_MSVC_X86
        #define CPUID_PLATFORM "win32_msvc_x86"
    #elif defined(_M_ARM) || defined(_M_ARMT)
        #define CPUID_WIN32_MSVC_ARM
        #define CPUID_PLATFORM "win32_msvc_arm"
    #endif
#elif defined(CPUID_MAC_LLVM)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_MAC_LLVM_X86
        #define CPUID_PLATFORM "mac_llvm_x86"
    #endif
#elif defined(CPUID_MAC_GCC)
    #if defined(__i386__) || defined(__x86_64__)
        #define CPUID_MAC_GCC_X86
        #define CPUID_PLATFORM "mac_gcc_x86"
    #endif
#elif defined(CPUID_IOS_LLVM)
    #pragma message "CPUID_IOS_LLVM"
    #define CPUID_IOS_LLVM_ARM
    #define CPUID_PLATFORM "ios_llvm_arm"
#else
    #define CPUID_UNKNOWN
    #define CPUID_PLATFORM "unknown"
    #pragma message "Warning: CPUID_PLATFORM is unknown"
#endif

#if !defined(CPUID_PLATFORM)
    #error "CPUID_PLATFORM is not defined"
#endif
