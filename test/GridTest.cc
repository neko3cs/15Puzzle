#include "gtest/gtest.h"
#include "../src/Grid.h"

TEST(GridTest, GetXReturnCorrectValue)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetX());
}

TEST(GridTest, GetYReturnCorrectValue)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetY());
}

TEST(GridTest, GetReturnCorrectValue)
{
    Grid grid(1, 1, 1);
    EXPECT_EQ(1, grid.GetY());
}
