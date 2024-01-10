#include "Board.h"
#include "Panel.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm> //shuffle()用
#include <random>    //default_random_engine()用
#include <chrono>    //system_clock()用

Board::Board()
{
}

std::vector<Panel>::iterator Board::GetPanelIterByDirection(Panel panel, MoveDirection direction)
{
    // TODO: 枠沿いのパネルの当たり判定の実装（移動負荷の場合は入れ替えない）

    int targetX = panel.GetGrid().GetX();
    int targetY = panel.GetGrid().GetY();

    switch (direction)
    {
    case MoveDirection::Up:
        targetX -= 1;
        break;
    case MoveDirection::Right:
        targetY += 1;
        break;
    case MoveDirection::Down:
        targetX += 1;
        break;
    case MoveDirection::Left:
        targetY -= 1;
        break;
    default:
        throw std::invalid_argument("invalid direction.");
    }

    return std::find_if(board.begin(), board.end(), [&targetX, &targetY](Panel p)
                        { return p.GetGrid().GetX() == targetX && p.GetGrid().GetY() == targetY; });
}

int Board::GetRow()
{
    return ROW;
}

int Board::GetColumn()
{
    return COL;
}

void Board::Initialize()
{
    // 時間ベースのシードを取得
    unsigned seed =
        std::chrono::system_clock::now().time_since_epoch().count();

    // 仮のコンテナにROW*COL分の数字を格納する
    std::vector<int> panelNums;
    for (int num = 1; num <= ROW * COL; num++)
    {
        panelNums.push_back(num);
    }

    // ランダムにシャッフルする
    auto engine = std::default_random_engine(seed);
    shuffle(panelNums.begin(), panelNums.end(), engine);

    // 仮コンテナのシャッフルした数字をボードに並べる
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

Panel Board::GetPanelByCoord(int x, int y)
{
    return board[x * ROW + y];
}

void Board::MovePanel(MoveDirection direction)
{
    auto hiddenPanelIter = std::find_if(board.begin(), board.end(), [](Panel p)
                                        { return p.IsHidden(); });
    auto changePanelIter = this->GetPanelIterByDirection(*hiddenPanelIter, direction);
    std::iter_swap(hiddenPanelIter, changePanelIter);
}
