#pragma once
#include <vector>
#include "Panel.h"

using namespace std;

class Board
{
	vector<Panel> board; //Number型のvectorコンテナ
public:
	Board(); //constractor
	const int ROW;
	const int COL;
	void show();
	void initialize();
};
