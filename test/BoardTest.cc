#include "gtest/gtest.h"
#include "../src/Board.h"
#include <iostream>

TEST(BoardTest, GetRowReturnCorrectValue)
{
    Board board;
    EXPECT_EQ(4, board.GetRow());
}

TEST(BoardTest, GetColumnReturnCorrectValue)
{
    Board board;
    EXPECT_EQ(4, board.GetColumn());
}

// FIXME: シャッフル関数のせいでテスト容易性が低い
// TEST(BoardTest, InitializeTest)
// {
//     Board board;
//     EXPECT_EQ(16, board.GetPanelByCoord().size());
// }
