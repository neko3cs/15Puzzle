#pragma once

class Panel
{
private:
	int num; //パネルの番号
	int x;
	int y;

public:
	Panel();
	Panel(int num, int x, int y);
	int GetNum();
	int GetX();
	int GetY();
};
