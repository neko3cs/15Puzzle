#pragma once
#include <vector>
#include "Panel.h"

class BoardManager
{
private:
	const int ROW;
	const int COL;
	std::vector<Panel> board;
public:
	BoardManager();
	int GetRow();
	int GetColumn();
	void Initialize();
	std::vector<Panel> GetBoard();
};
