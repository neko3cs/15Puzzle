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
