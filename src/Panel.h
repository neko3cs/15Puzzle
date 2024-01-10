#pragma once
#include "Grid.h"
#include <string>

class Panel
{
private:
	Panel();
	int HIDDEN_NUM = 1;
	Grid grid;

public:
	Panel(Grid grid);
	std::string ToString();
	Grid GetGrid();
	bool IsHidden();
};
