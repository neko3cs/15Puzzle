#include "gtest/gtest.h"
#include "../src/Grid.h"

TEST(GridTest, GetXTest)
{
    Grid Grid(1, 1, 1);
    EXPECT_EQ(1, Grid.GetX());
}

TEST(GridTest, GetYTest)
{
    Grid Grid(1, 1, 1);
    EXPECT_EQ(1, Grid.GetY());
}

TEST(GridTest, GetNumTest)
{
    Grid Grid(1, 1, 1);
    EXPECT_EQ(1, Grid.GetY());
}

TEST(GridTest, ToStringTest)
{
    Grid Grid(1, 1, 1);
    EXPECT_EQ("x=1, y=1, num=1", Grid.ToString());
}
