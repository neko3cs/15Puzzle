#include "Board.hpp"
#include "Panel.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm> //shuffle()用
#include <random>    //default_random_engine()用
#include <chrono>    //system_clock()用

Board::Board()
{
}

void Board::Initialize()
{
  // 時間ベースのシードを取得
  unsigned seed =
      std::chrono::system_clock::now().time_since_epoch().count();

  // 仮のコンテナにSIZE*SIZE分の数字を格納する
  std::vector<int> numbers;
  for (int num = 1; num <= SIZE * SIZE; num++)
  {
    numbers.push_back(num);
  }

  // ランダムにシャッフルする
  auto engine = std::default_random_engine(seed);
  std::shuffle(numbers.begin(), numbers.end(), engine);

  // 仮コンテナのシャッフルした数字をボードに並べる
  for (int x = 0; x < SIZE; x++)
  {
    for (int y = 0; y < SIZE; y++)
    {
      Panel panel(numbers[x * SIZE + y]);
      board.push_back(panel);
    }
  }
}

void Board::Show()
{
  for (int x = 0; x < SIZE; x++)
  {
    for (int y = 0; y < SIZE; y++)
    {
      std::cout.width(2); // 可視性を上げる
      std::cout << board[x * SIZE + y].ToString() << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void Board::MovePanel(MoveDirection direction)
{
  auto hidden = std::find_if(board.begin(), board.end(), [](Panel p)
                             { return p.IsHidden(); });
  auto hiddenIndex = std::distance(board.begin(), hidden);

  auto targetIndex = -1;
  switch (direction)
  {
  case MoveDirection::Left:
    targetIndex = hiddenIndex - 1;
    break;
  case MoveDirection::Right:
    targetIndex = hiddenIndex + 1;
    break;
  case MoveDirection::Up:
    targetIndex = hiddenIndex - SIZE;
    break;
  case MoveDirection::Down:
    targetIndex = hiddenIndex + SIZE;
    break;
  default:
    throw std::invalid_argument("無効な方向が引き渡されました。");
  }

  if (targetIndex >= 0 &&                            // 左上端を突き抜けないこと
      targetIndex < SIZE * SIZE &&                   // 右下端を突き抜けないこと
      ((hiddenIndex / SIZE == targetIndex / SIZE) || // 同行に存在すること
       (hiddenIndex % SIZE == targetIndex % SIZE)))  // 同列に存在すること
  {
    std::swap(board[hiddenIndex], board[targetIndex]);
  }
}

bool Board::IsSolved()
{
  auto expected = 1;
  for (const auto &panel : board)
  {
    if (panel.GetNumber() != expected)
    {
      return false;
    }
    expected++;
  }

  return true;
}
