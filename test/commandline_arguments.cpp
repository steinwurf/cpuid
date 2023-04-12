// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <algorithm>
#include <vector>

#include "commandline_arguments.hpp"

namespace po = boost::program_options;

commandline_arguments::commandline_arguments()
{
    m_options.add_options()("no_fail", "The test should always return 0")(
        "has_fpu", po::value<bool>()->default_value(false))(
        "has_mmx", po::value<bool>()->default_value(false))(
        "has_sse", po::value<bool>()->default_value(false))(
        "has_sse2", po::value<bool>()->default_value(false))(
        "has_sse3", po::value<bool>()->default_value(false))(
        "has_ssse3", po::value<bool>()->default_value(false))(
        "has_sse4_1", po::value<bool>()->default_value(false))(
        "has_sse4_2", po::value<bool>()->default_value(false))(
        "has_pclmulqdq", po::value<bool>()->default_value(false))(
        "has_avx", po::value<bool>()->default_value(false))(
        "has_avx2", po::value<bool>()->default_value(false))(
        "has_avx512_f", po::value<bool>()->default_value(false))(
        "has_avx512_dq", po::value<bool>()->default_value(false))(
        "has_avx512_ifma", po::value<bool>()->default_value(false))(
        "has_avx512_pf", po::value<bool>()->default_value(false))(
        "has_avx512_er", po::value<bool>()->default_value(false))(
        "has_avx512_cd", po::value<bool>()->default_value(false))(
        "has_avx512_bw", po::value<bool>()->default_value(false))(
        "has_avx512_vl", po::value<bool>()->default_value(false))(
        "has_avx512_vbmi", po::value<bool>()->default_value(false))(
        "has_avx512_vbmi2", po::value<bool>()->default_value(false))(
        "has_avx512_vnni", po::value<bool>()->default_value(false))(
        "has_avx512_bitalg", po::value<bool>()->default_value(false))(
        "has_avx512_vpopcntdq", po::value<bool>()->default_value(false))(
        "has_avx512_4vnniw", po::value<bool>()->default_value(false))(
        "has_avx512_4fmaps", po::value<bool>()->default_value(false))(
        "has_avx512_vp2intersect", po::value<bool>()->default_value(false))(
        "has_f16c", po::value<bool>()->default_value(false))(
        "has_aes", po::value<bool>()->default_value(false))(
        "has_neon", po::value<bool>()->default_value(false));
}

po::variables_map commandline_arguments::parse(int argc, char** argv)
{
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, m_options), vm);
    po::notify(vm);

    return vm;
}
