#pragma once
#include <vector>
#include "Panel.h"
#include "MoveDirection.h"

class Board
{
private:
	const int ROW = 4;
	const int COL = 4;
	std::vector<Panel> board;	
	Panel GetPanelByCoord(int x, int y);
	std::vector<Panel>::iterator GetPanelIterByDirection(Panel panel, MoveDirection direction);

public:
	Board();
	void Initialize();
	void Show();
	void MovePanel(MoveDirection direction);
};
