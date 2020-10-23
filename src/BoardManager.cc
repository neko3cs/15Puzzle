#include "BoardManager.h"
#include "Panel.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm> //shuffle()用
#include <random>    //default_random_engine()用
#include <chrono>    //system_clock()用

BoardManager::BoardManager()
    : ROW(4), COL(4)
{
    Initialize();
}

int BoardManager::GetRow()
{
    return ROW;
}

int BoardManager::GetColumn()
{
    return COL;
}

void BoardManager::Initialize()
{
    //時間ベースのシードを取得
    unsigned seed =
        chrono::system_clock::now().time_since_epoch().count();

    //仮のコンテナにROW*COL分の数字を格納する
    vector<int> panelNums;
    for (int num = 1; num <= ROW * COL; num++)
    {
        panelNums.push_back(num);
    }

    //ランダムにシャッフルする
    auto engine = default_random_engine(seed);
    shuffle(panelNums.begin(), panelNums.end(), engine);

    //仮コンテナのシャッフルした数字をボードに並べる
    for (int x = 0; x < ROW; x++)
    {
        for (int y = 0; y < COL; y++)
        {
            Grid grid(x, y, panelNums.at(x * ROW + y));
            Panel panel(grid);
            board.push_back(panel);
        }
    }
}

vector<Panel> BoardManager::GetBoard()
{
    return board;
}