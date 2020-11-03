#include "gtest/gtest.h"
#include "../src/BoardManager.h"
#include <iostream>

TEST(BoardManagerTest, GetRowReturnCorrectValue)
{
    BoardManager boardManager;
    EXPECT_EQ(4, boardManager.GetRow());
}

TEST(BoardManagerTest, GetColumnReturnCorrectValue)
{
    BoardManager boardManager;
    EXPECT_EQ(4, boardManager.GetColumn());
}

// FIXME: シャッフル関数のせいでテスト容易性が低い
// TEST(BoardManagerTest, InitializeTest)
// {
//     BoardManager boardManager;
//     EXPECT_EQ(16, boardManager.GetPanelByCoord().size());
// }
