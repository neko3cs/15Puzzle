#include "FifteenPuzzle.h"
#include <iostream>

FifteenPuzzle::FifteenPuzzle()
{
    board.Initialize();
}

void FifteenPuzzle::Run()
{
    while (true)
    {
        board.Show();

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
