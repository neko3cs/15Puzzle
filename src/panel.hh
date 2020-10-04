#pragma once

class panel{
	int num;  //パネルの番号
	int x;
	int y;
public:
    panel();
	panel(int num, int x, int y);
	int get_num();
	int get_x();
	int get_y();
};
