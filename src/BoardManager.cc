#include "BoardManager.h"
#include "Number.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  //shuffle()用
#include <random>  //default_random_engine()用
#include <chrono>  //system_clock()用

using namespace std;

void BoardManager::initialize(){
    //時間ベースのシードを取得
    unsigned seed =
        chrono::system_clock::now().time_since_epoch().count();
	
    //仮のコンテナにROW*COL分の数字を格納する
    vector<int> numbers;
	for(int num = 1; num <= ROW*COL; num++){
		numbers.push_back(num);
	}
	
    //ランダムにシャッフルする
    auto engine = default_random_engine(seed);
	shuffle(numbers.begin(), numbers.end(), engine);
	
    //仮コンテナのシャッフルした数字をボードに並べる
	for(int x=0; x<ROW; x++){
		for(int y=0; y<COL; y++){
			Number number = Number(numbers.at(x*ROW+y), x, y);
			board.push_back(number);
		}
	}
}

BoardManager::BoardManager()
	: ROW(4), COL(4)
{
	initialize();
}

void BoardManager::show(){
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            cout.width(2);  //可視性を上げる
            cout <<  board[i*ROW+j].getNum() << ' ';
        }
        cout << endl;
    }
}
