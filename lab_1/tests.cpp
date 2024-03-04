#include <gtest/gtest.h>
#include "task.hpp"

TEST(FindDevider, Positive)
{
    ASSERT_TRUE(find_devider(5, 10) == 5);
    ASSERT_TRUE(find_devider(1, 1) == 1);
    ASSERT_TRUE(find_devider(30, 18) == 6);
}

TEST(FindDevider, Custom)
{
    ASSERT_TRUE(find_devider(0, 1) == 1);
    ASSERT_TRUE(find_devider(-1, 1) == 1);
    ASSERT_TRUE(find_devider(30, 6) == 6);
}

TEST(FindDevider, Negative)
{
    ASSERT_TRUE(find_devider(-2, -1) == 1);
    ASSERT_TRUE(find_devider(-5, 2) == 1);
    ASSERT_TRUE(find_devider(4, -20) == 4);
}