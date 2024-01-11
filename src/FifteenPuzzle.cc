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
    std::cout << "Input direction(H: Left, J: Up, K: Down, L: Right) or quit(q, quit): " << std::flush;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (input == 'q')
    {
      std::cout << "Exit" << std::endl;
      break;
    }
    else if (input == 'h' || input == 'H')
    {
      board.MovePanel(MoveDirection::Left);
    }
    else if (input == 'l' || input == 'L')
    {
      board.MovePanel(MoveDirection::Right);
    }
    else if (input == 'j' || input == 'J')
    {
      board.MovePanel(MoveDirection::Up);
    }
    else if (input == 'k' || input == 'K')
    {
      board.MovePanel(MoveDirection::Down);
    }
    else
    {
      std::cout << "Invalid character was inputted: " << input << std::endl;
    }

    if (board.IsSolved())
    {
      // パズルが解けたら褒めて終了
      std::cout << "Congratulations! You solved puzzle!" << std::endl;
      break;
    }
  }
}
