#pragma once

using namespace std;

class GridPoint{
	int x;
	int y;
public:
	GridPoint(int x, int y);  //constractor
	int getX();
	int getY();
	string toString();
};
