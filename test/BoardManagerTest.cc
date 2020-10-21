#include "gtest/gtest.h"
#include "../src/BoardManager.h"
#include <iostream>

TEST(BoardManagerTest, InitTest)
{
    Board board();

    // TODO: テスト容易性が低いので設計を見直す
    EXPECT_EQ(1, 1);
}
