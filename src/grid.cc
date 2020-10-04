#include "grid.h"
#include <string.h>

using namespace std;

grid::grid(int x, int y)
	: x(x), y(y)
{}

int grid::get_x(){
	return x;
}

int grid::get_y(){
	return y;
}

string grid::to_string(){
	string str = string.format("x=%d, y=%d", x, y);  //written in java
	return str;
}
