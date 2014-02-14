#include <cstdint>
#include <ctime>
#include <gtest/gtest.h>

#include <boost/program_options.hpp>
#include "commandline_arguments.hpp"

boost::program_options::variables_map variable_map;

GTEST_API_ int main(int argc, char** argv)
{

    testing::InitGoogleTest(&argc, argv);

    commandline_arguments cmd_args;

    variable_map = cmd_args.parse(argc,argv);

    int result = RUN_ALL_TESTS();
    // The no_fail option is used when the CPU instruction sets are not
    // well-known, e.g. when running with valgrind or on a virtual machine
    if (variable_map.count("no_fail")) result = 0;
    return result;
}
