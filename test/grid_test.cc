#include "gtest/gtest.h"
#include "../src/grid.h"

TEST(GridTest, GetXTest)
{
    grid grid(1, 1);
    EXPECT_EQ(1, grid.get_x());
}

TEST(GridTest, GetYTest)
{
    grid grid(1, 1);
    EXPECT_EQ(1, grid.get_y());
}

TEST(GridTest, ToStringTest)
{
    grid grid(1, 1);
    EXPECT_EQ("x=1, y=1", grid.to_string());
}
