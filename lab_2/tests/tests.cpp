#include <gtest/gtest.h>
#include "../include/Hex.h"


TEST(hex, Constructor)
{
    Hex hex1("A23F");
    ASSERT_TRUE(hex1.toString() == "A23F");

    Hex hex2({1, 2, 3, 4, 5});
    ASSERT_TRUE(hex2.toString() == "12345");

    Hex hex3(hex1);
    ASSERT_TRUE(hex3.toString() == "A23F");

    Hex hex4;
    ASSERT_TRUE(hex4.toString() == "0");
}

TEST(hex, Assigment)
{
    Hex hex1("A23F");
    Hex hex2("4567");
    hex2 = hex1;
    ASSERT_TRUE(hex2.toString() == "A23F");

    Hex hex3("1234");
    hex3 = hex3;
    ASSERT_TRUE(hex3.toString() == "1234");
}

TEST(hex, Addition)
{
    Hex hex1("A23F");
    Hex hex2("4567");
    hex1 += hex2;
    ASSERT_TRUE(hex1.toString() == "E7A6");

    Hex hex3("FF");
    hex3 += hex3;
    ASSERT_TRUE(hex3.toString() == "1FE");

    Hex hex4("123");
    hex4 += hex4;
    ASSERT_TRUE(hex4.toString() == "246");
}

TEST(hex, Substruction)
{
    Hex hex1("A23F");
    Hex hex2("4567");
    hex1 -= hex2;
    ASSERT_TRUE(hex1.toString() == "5CD8");

    Hex hex3("ABC");
    hex3 -= hex3;
    ASSERT_TRUE(hex3.toString() == "0");

    Hex hex4("1234");
    hex4 -= hex4;
    ASSERT_TRUE(hex4.toString() == "0");
}

TEST(hex, Comparison)
{
    Hex hex1("A23F");
    Hex hex2("4567");
    Hex hex3("A23F");

    ASSERT_TRUE(hex1 != hex2);
    ASSERT_TRUE(hex1 == hex3);
    ASSERT_TRUE(hex2 < hex1);
    ASSERT_TRUE(hex2 <= hex1);
    ASSERT_TRUE(hex1 > hex2);
    ASSERT_TRUE(hex1 >= hex2);
}