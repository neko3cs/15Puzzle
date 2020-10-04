#include "../src/board.h"
#include <iostream>

using namespace std;

board board;

int main(void){
    board board = board();
    
    board.show();
    
    return 0;
}
