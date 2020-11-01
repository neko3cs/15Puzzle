#include "gtest/gtest.h"
#include "../src/Grid.h"
#include "../src/Panel.h"
#include <iostream>

TEST(PanelTest, GetGridTest)
{
	Grid grid(1, 1, 1);
	Panel panel(grid);
	EXPECT_EQ(grid.ToString(), panel.GetGrid().ToString());
}

TEST(PanelTest, IsHiddenTest)
{
	Grid hideGrid(1, 1, 1);
	Panel hidePanel(hideGrid);
	EXPECT_EQ(true, hidePanel.IsHidden());

	Grid grid(1, 1, 2);
	Panel panel(grid);
	EXPECT_EQ(false, panel.IsHidden());
}
