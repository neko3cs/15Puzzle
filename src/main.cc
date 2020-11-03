#include "BoardManager.h"
#include <iostream>

void ShowBoard(BoardManager boardManager);

int main(int argc, char const *argv[])
{
    BoardManager boardManager;

    ShowBoard(boardManager);

    return 0;
}

void ShowBoard(BoardManager boardManager)
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
