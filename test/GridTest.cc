#include "gtest/gtest.h"
#include "../src/Grid.h"

TEST(GridTest, GetXTest)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetX());
}

TEST(GridTest, GetYTest)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetY());
}

TEST(GridTest, GetNumTest)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetY());
}

TEST(GridTest, ToStringTest)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ("x=1, y=1, num=1", grid.ToString());
}
