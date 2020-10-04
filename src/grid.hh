#pragma once

using namespace std;

class grid{
	int x;
	int y;
public:
	grid(int x, int y);  //constractor
	int get_x();
	int get_y();
	string to_string();
};
