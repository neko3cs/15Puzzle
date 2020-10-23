#pragma once
#include <vector>
#include "Panel.h"

using namespace std;

class BoardManager
{
private:
	const int ROW;
	const int COL;
	vector<Panel> board;

public:
	BoardManager();
	int GetRow();
	int GetColumn();
	void Initialize();
	vector<Panel> GetBoard();
};
