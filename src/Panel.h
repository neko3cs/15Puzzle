#pragma once
#include "Grid.h"

class Panel
{
private:
	Panel();
	Grid grid;
	// TODO: 分割した画像変数を持つ

public:
	Panel(Grid grid);
	Grid GetGrid();
};
