#pragma once

class Grid
{
private:
	Grid();
	int x;
	int y;
	int num;

public:
	Grid(int x, int y, int num);
	int GetX();
	int GetY();
	int GetNum();
};
