#pragma once
#include <vector>
#include "Panel.h"

using namespace std;

class Board
{
private:
	vector<Panel> board;

public:
	Board();
	const int ROW;
	const int COL;
	void Initialize();
	void Show();
};
