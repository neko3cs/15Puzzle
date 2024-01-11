#pragma once
#include <vector>
#include "Panel.h"
#include "MoveDirection.h"

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
};
