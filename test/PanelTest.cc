#include "gtest/gtest.h"
#include "../src/Grid.h"
#include "../src/Panel.h"
#include <iostream>

TEST(PanelTest, ToStringReturnSquare)
{
	Grid grid(1, 1, 1);
	Panel panel(grid);
	EXPECT_EQ("■ ", panel.ToString());
}

TEST(PanelTest, ToStringReturnNumber)
{
	Grid grid(1, 1, 2);
	Panel panel(grid);
	EXPECT_EQ("2", panel.ToString());
}

TEST(PanelTest, GetGridReturnSameGrid)
{
	Grid grid(1, 1, 1);
	Panel panel(grid);
	EXPECT_EQ(grid.GetX(), panel.GetGrid().GetX());
	EXPECT_EQ(grid.GetY(), panel.GetGrid().GetY());
	EXPECT_EQ(grid.GetNum(), panel.GetGrid().GetNum());
}

TEST(PanelTest, IsHiddenReturnTrue)
{
	Grid hideGrid(1, 1, 1);
	Panel hidePanel(hideGrid);
	EXPECT_EQ(true, hidePanel.IsHidden());
}

TEST(PanelTest, IsHiddenReturnFalse)
{
	Grid grid(1, 1, 2);
	Panel panel(grid);
	EXPECT_EQ(false, panel.IsHidden());
}
