#include "Panel.h"

Panel::Panel(int num, int x, int y)
	: num(num), x(x), y(y)
{
}

int Panel::GetNum()
{
	return num;
}

int Panel::GetX()
{
	return x;
}

int Panel::GetY()
{
	return y;
}
