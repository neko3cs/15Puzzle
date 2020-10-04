#pragma once
#include <vector>
#include "panel.h"

using namespace std;

class board{
    vector<panel> board;  //Number型のvectorコンテナ
public:
	board();  //constractor
	const int ROW;
	const int COL;
    void show();
	void initialize();
};
