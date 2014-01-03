#include <cstdint>
#include <ctime>
#include <gtest/gtest.h>

#include <boost/program_options.hpp>
#include "commandline_arguments.hpp"


namespace po = boost::program_options;

po::variables_map variable_map;

GTEST_API_ int main(int argc, char** argv)
{
    srand(static_cast<uint32_t>(time(0)));

    testing::InitGoogleTest(&argc, argv);

    commandline_arguments cmd_args;

    variable_map = cmd_args.parse(argc,argv);

    if (variable_map.count("help_cpuid"))
    {
        cmd_args.print_help();
        return 0;
    }


    return RUN_ALL_TESTS();

}
