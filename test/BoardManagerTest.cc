#include "gtest/gtest.h"
#include "../src/board.h"
#include <iostream>

TEST(BoardTest, InitTest)
{
    Board board();

    // TODO: テスト容易性が低いので設計を見直す
    EXPECT_EQ(1, 1);
}
