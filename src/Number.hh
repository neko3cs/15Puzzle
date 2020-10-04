#pragma once

class Number{
	int num;  //パネルの番号
	int x;
	int y;
public:
    Number();
	Number(int num, int x, int y);
	int getNum();
	int getX();
	int getY();
};
