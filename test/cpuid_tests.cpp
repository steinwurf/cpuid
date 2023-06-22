// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <CLI/CLI.hpp>
#include <cstdint>
#include <gtest/gtest.h>
#include <map>

std::map<std::string, bool> variable_map;

GTEST_API_ int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    CLI::App app;
    app.add_flag("--no_fail", variable_map["no_fail"],
                 "The test should always return 0");

    app.add_flag("--has_fpu", variable_map["has_fpu"],
                 "Flag indicating presence of FPU");
    app.add_flag("--has_mmx", variable_map["has_mmx"],
                 "Flag indicating presence of MMX");
    app.add_flag("--has_sse", variable_map["has_sse"],
                 "Flag indicating presence of SSE");
    app.add_flag("--has_sse2", variable_map["has_sse2"],
                 "Flag indicating presence of SSE2");
    app.add_flag("--has_sse3", variable_map["has_sse3"],
                 "Flag indicating presence of SSE3");
    app.add_flag("--has_ssse3", variable_map["has_ssse3"],
                 "Flag indicating presence of SSSE3");
    app.add_flag("--has_sse4_1", variable_map["has_sse4_1"],
                 "Flag indicating presence of SSE4.1");
    app.add_flag("--has_sse4_2", variable_map["has_sse4_2"],
                 "Flag indicating presence of SSE4.2");
    app.add_flag("--has_pclmulqdq", variable_map["has_pclmulqdq"],
                 "Flag indicating presence of PCLMULQDQ");
    app.add_flag("--has_avx", variable_map["has_avx"],
                 "Flag indicating presence of AVX");
    app.add_flag("--has_avx2", variable_map["has_avx2"],
                 "Flag indicating presence of AVX2");
    app.add_flag("--has_avx512_f", variable_map["has_avx512_f"],
                 "Flag indicating presence of AVX-512 F");
    app.add_flag("--has_avx512_dq", variable_map["has_avx512_dq"],
                 "Flag indicating presence of AVX-512 DQ");
    app.add_flag("--has_avx512_ifma", variable_map["has_avx512_ifma"],
                 "Flag indicating presence of AVX-512 IFMA");
    app.add_flag("--has_avx512_pf", variable_map["has_avx512_pf"],
                 "Flag indicating presence of AVX-512 PF");
    app.add_flag("--has_avx512_er", variable_map["has_avx512_er"],
                 "Flag indicating presence of AVX-512 ER");
    app.add_flag("--has_avx512_cd", variable_map["has_avx512_cd"],
                 "Flag indicating presence of AVX-512 CD");
    app.add_flag("--has_avx512_bw", variable_map["has_avx512_bw"],
                 "Flag indicating presence of AVX-512 BW");
    app.add_flag("--has_avx512_vl", variable_map["has_avx512_vl"],
                 "Flag indicating presence of AVX-512 VL");
    app.add_flag("--has_avx512_vbmi", variable_map["has_avx512_vbmi"],
                 "Flag indicating presence of AVX-512 VBMI");
    app.add_flag("--has_avx512_vbmi2", variable_map["has_avx512_vbmi2"],
                 "Flag indicating presence of AVX-512 VBMI2");
    app.add_flag("--has_avx512_vnni", variable_map["has_avx512_vnni"],
                 "Flag indicating presence of AVX-512 VNNI");
    app.add_flag("--has_avx512_bitalg", variable_map["has_avx512_bitalg"],
                 "Flag indicating presence of AVX-512 BITALG");
    app.add_flag("--has_avx512_vpopcntdq", variable_map["has_avx512_vpopcntdq"],
                 "Flag indicating presence of AVX-512 VPOPCNTDQ");
    app.add_flag("--has_avx512_4vnniw", variable_map["has_avx512_4vnniw"],
                 "Flag indicating presence of AVX-512 4VNNIW");
    app.add_flag("--has_avx512_4fmaps", variable_map["has_avx512_4fmaps"],
                 "Flag indicating presence of AVX-512 4FMAPS");
    app.add_flag("--has_avx512_vp2intersect",
                 variable_map["has_avx512_vp2intersect"],
                 "Flag indicating presence of AVX-512 VP2INTERSECT");
    app.add_flag("--has_f16c", variable_map["has_f16c"],
                 "Flag indicating presence of F16C");
    app.add_flag("--has_aes", variable_map["has_aes"],
                 "Flag indicating presence of AES");
    app.add_flag("--has_neon", variable_map["has_neon"],
                 "Flag indicating presence of NEON");
    // Add more flags for other options...

    CLI11_PARSE(app, argc, argv);

    int result = RUN_ALL_TESTS();
    // The no_fail option is used when the CPU instruction sets are not
    // well-known, e.g. when running with valgrind or on a virtual machine
    if (variable_map.count("no_fail"))
        result = 0;
    return result;
}
