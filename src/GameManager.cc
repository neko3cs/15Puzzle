#include "GameManager.h"
#include <iostream>

void GameManager::ShowBoard()
{
    for (int i = 0; i < board.GetRow(); i++)
    {
        for (int j = 0; j < board.GetColumn(); j++)
        {
            std::cout.width(2); // 可視性を上げる
            std::cout << board.GetPanelByCoord(i, j).ToString() << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

GameManager::GameManager()
{
    board.Initialize();
}

void GameManager::Run()
{
    while (true)
    {
        this->ShowBoard();

        char input;
        std::cout << "Input direction(H: Left, J: Up, K: Down, L: Right) or quit(q, quit): " << std::endl;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input == 'q')
        {
            std::cout << "Exit" << std::endl;
            break;
        }
        else if (input == 'h' || input == 'H')
        {
            std::cout << "Direction is Left" << std::endl;
        }
        else if (input == 'j' || input == 'J')
        {
            std::cout << "Direction is Up" << std::endl;
        }
        else if (input == 'k' || input == 'K')
        {
            std::cout << "Direction is Down" << std::endl;
        }
        else if (input == 'l' || input == 'L')
        {
            std::cout << "Direction is Right" << std::endl;
        }
        else
        {
            std::cout << "Input char is: " << input << std::endl;
        }
    }
}
