#include <iostream>
#include "FifteenPuzzle.hpp"

FifteenPuzzle::FifteenPuzzle()
{
  board.Initialize();
}

void FifteenPuzzle::RunAsCli()
{
  while (true)
  {
    board.Show();

    char input;
    std::cout << "隠れパネルの移動(Hキー: 左移動, Jキー: 上移動, Kキー: 下移動, Lキー: 右移動)、終了(qキー): " << std::flush;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (input == 'q')
    {
      std::cout << "ゲームを終了します。" << std::endl;
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
      std::cout << "無効な文字が入力されました: " << input << std::endl;
    }

    if (board.IsSolved())
    {
      // パズルが解けたら褒めて終了
      std::cout << "おめでとうございます！パズルが解けました！" << std::endl;
      break;
    }
  }
}