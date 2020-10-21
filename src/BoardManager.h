#pragma once
#include <vector>
#include "Panel.h"

using namespace std;

class Board
{
private:
	const int ROW;
	const int COL;
	vector<Panel> board;

public:
	Board();
	void Initialize();
	void Show();
};
