#include "../src/panel.h"
#include <iostream>

using namespace std;

panel panel;

void get_num_test(){
	cout << panel.get_num() << endl;
}

void get_x_test(){
	cout << panel.get_x() << endl;
}

void get_y_test(){
	cout << panel.get_y() << endl;
}

int main(void){
	panel = panel(1, 0, 0);
	get_num_test();
	get_x_test();
	get_y_test();
}
