#pragma once
#include "Grid.h"
#include <string>

class Panel
{
private:
	Panel();
	Grid grid;

public:
	Panel(Grid grid);
	std::string ToString();
	bool IsHidden();
};
