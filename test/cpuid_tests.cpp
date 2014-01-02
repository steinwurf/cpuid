#include <cstdint>
#include <ctime>
#include <gtest/gtest.h>
#include <cpuid/commandline_arguments.hpp>
#include <string>


cpuid::commandline_arguments test_commandline_arguments;

GTEST_API_ int main(int argc, char** argv)
{
    srand(static_cast<uint32_t>(time(0)));

    testing::InitGoogleTest(&argc, argv);
    test_commandline_arguments.parse(argc,argv);

    return RUN_ALL_TESTS();

}
