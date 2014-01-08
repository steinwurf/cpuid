#include <vector>
#include <algorithm>

#include "commandline_arguments.hpp"

namespace po = boost::program_options;

commandline_arguments::commandline_arguments()
{
    m_options.add_options()
        ("has_fpu", po::value<bool>()->default_value(false))
        ("has_mmx", po::value<bool>()->default_value(false))
        ("has_sse", po::value<bool>()->default_value(false))
        ("has_sse2", po::value<bool>()->default_value(false))
        ("has_sse3", po::value<bool>()->default_value(false))
        ("has_ssse3", po::value<bool>()->default_value(false))
        ("has_sse4_1", po::value<bool>()->default_value(false))
        ("has_sse4_2", po::value<bool>()->default_value(false))
        ("has_pclmulqdq", po::value<bool>()->default_value(false))
        ("has_avx", po::value<bool>()->default_value(false));
}

po::variables_map commandline_arguments::parse(int argc, char **argv)
{
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, m_options), vm);
    po::notify(vm);

    return vm;
}
