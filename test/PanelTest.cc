#include "../src/Panel.h"
#include <iostream>

using namespace std;

Panel panel;

void GetNumTest()
{
	cout << panel.GetNum() << endl;
}

void GetXTest()
{
	cout << panel.GetX() << endl;
}

void GetYTest()
{
	cout << panel.GetY() << endl;
}

int main(void)
{
	Panel panel(1, 0, 0);
	GetNumTest();
	GetXTest();
	GetYTest();
}
