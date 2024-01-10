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
	void SetX(int x);
	int GetY();
	void SetY(int y);
	int GetNum();
};
