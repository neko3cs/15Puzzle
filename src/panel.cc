#include "panel.h"

panel::panel(int num, int x, int y)
	:num(num), x(x), y(y)
{}

int panel::get_num(){
	return num;
}

int panel::get_x(){
	return x;
}

int panel::get_y(){
	return y;
}
