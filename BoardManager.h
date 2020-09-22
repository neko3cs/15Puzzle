#pragma once
#include <vector>
#include "Number.h"

using namespace std;

class BoardManager{
    vector<Number> board;  //Number型のvectorコンテナ
public:
	BoardManager();  //constractor
	const int ROW;
	const int COL;
    void show();
	void initialize();
};


