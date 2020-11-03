#pragma once
#include "Grid.h"

class Panel
{
private:
	Panel();
	Grid grid;
public:
	Panel(Grid grid);
	Grid GetGrid();
	bool IsHidden();
};
