#include "../src/Number.h"
#include <iostream>

using namespace std;

Number number;

void getNumTest(){
	cout << number.getNum() << endl;
}

void getXtest(){
	cout << number.getX() << endl;
}

void getYtest(){
	cout << number.getY() << endl;
}

int main(void){
	number = Number(1, 0, 0);
	getNumTest();
	getXtest();
	getYtest();
}
