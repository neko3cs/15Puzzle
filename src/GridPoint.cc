#include "GridPoint.h"
#include <string.h>

using namespace std;

GridPoint::GridPoint(int x, int y)
	: x(x), y(y)
{}

int GridPoint::getX(){
	return x;
}

int GridPoint::getY(){
	return y;
}

string GridPoint::toString(){
	string str = string.format("x=%d, y=%d", x, y);  //written in java
	return str;
}
