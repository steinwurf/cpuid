#include <cstdint>
#include <ctime>
#include <gtest/gtest.h>

GTEST_API_ int main(int argc, char** argv)
{
    srand(static_cast<uint32_t>(time(0)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
