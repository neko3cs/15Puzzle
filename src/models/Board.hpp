#pragma once
#include <vector>
#include "Panel.hpp"
#include "MoveDirection.hpp"

class Board
{
private:
	const int SIZE = 4;
	std::vector<Panel> board;

public:
	Board();
	void Initialize();
	void Show();
	void MovePanel(MoveDirection direction);
	bool IsSolved();
};
