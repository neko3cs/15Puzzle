#include "board.h"
#include "panel.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  //shuffle()用
#include <random>  //default_random_engine()用
#include <chrono>  //system_clock()用

using namespace std;

void board::initialize(){
    //時間ベースのシードを取得
    unsigned seed =
        chrono::system_clock::now().time_since_epoch().count();
	
    //仮のコンテナにROW*COL分の数字を格納する
    vector<int> panels;
	for(int num = 1; num <= ROW*COL; num++){
		panels.push_back(num);
	}
	
    //ランダムにシャッフルする
    auto engine = default_random_engine(seed);
	shuffle(panels.begin(), panels.end(), engine);
	
    //仮コンテナのシャッフルした数字をボードに並べる
	for(int x=0; x<ROW; x++){
		for(int y=0; y<COL; y++){
			panel panel = panel(panels.at(x*ROW+y), x, y);
			board.push_back(panel);
		}
	}
}

board::board()
	: ROW(4), COL(4)
{
	initialize();
}

void board::show(){
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            cout.width(2);  //可視性を上げる
            cout <<  board[i*ROW+j].get_num() << ' ';
        }
        cout << endl;
    }
}
