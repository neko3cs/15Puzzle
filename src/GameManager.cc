#include "GameManager.h"
#include <iostream>

void GameManager::ShowBoard()
{
    for (int i = 0; i < boardManager.GetRow(); i++)
    {
        for (int j = 0; j < boardManager.GetColumn(); j++)
        {
            std::cout.width(2); //可視性を上げる
            std::cout << boardManager.GetPanelByCoord(i, j).ToString() << ' ';
        }
        std::cout << std::endl;
    }
}

GameManager::GameManager()
{
    boardManager.Initialize();
}

void GameManager::Start()
{
    // TODO: ここでループしたり■を動かす
    this->ShowBoard();
}
