#include "gtest/gtest.h"
#include "../src/BoardManager.h"
#include <iostream>

TEST(BoardManagerTest, GetRowTest)
{
    BoardManager boardManager;
    EXPECT_EQ(4, boardManager.GetRow());
}

TEST(BoardManagerTest, GetColumnTest)
{
    BoardManager boardManager;
    EXPECT_EQ(4, boardManager.GetColumn());
}

TEST(BoardManagerTest, InitializeTest)
{
    BoardManager boardManager;
    EXPECT_EQ(16, boardManager.GetBoard().size());
}
