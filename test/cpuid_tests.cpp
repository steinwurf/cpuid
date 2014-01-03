#include <cstdint>
#include <ctime>
#include <gtest/gtest.h>
#include <cpuid/commandline_arguments.hpp>
#include <string>

cpuid::po::variables_map cpuid::variable_map;

GTEST_API_ int main(int argc, char** argv)
{
    srand(static_cast<uint32_t>(time(0)));

    testing::InitGoogleTest(&argc, argv);

    cpuid::commandline_arguments cmd_args;

    cpuid::variable_map = cmd_args.parse(argc,argv);

    return RUN_ALL_TESTS();

}
