#include "Number.h"

Number::Number(int num, int x, int y)
	:num(num), x(x), y(y)
{}

int Number::getNum(){
	return num;
}

int Number::getX(){
	return x;
}

int Number::getY(){
	return y;
}
