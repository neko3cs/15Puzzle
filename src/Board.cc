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

Panel Board::GetPanelByCoord(int x, int y)
{
    return board[x + y * ROW];
}

std::vector<Panel>::iterator Board::GetPanelIterByDirection(Panel panel, MoveDirection direction)
{
    int targetX = panel.GetGrid().GetX();
    int targetY = panel.GetGrid().GetY();

    switch (direction)
    {
    case MoveDirection::Left:
        targetX -= 1;
        break;
    case MoveDirection::Right:
        targetX += 1;
        break;
    case MoveDirection::Up:
        targetY -= 1;
        break;
    case MoveDirection::Down:
        targetY += 1;
        break;
    default:
        throw std::invalid_argument("invalid direction.");
    }

    return std::find_if(board.begin(), board.end(), [&targetX, &targetY](Panel p)
                        { return p.GetGrid().GetX() == targetX && p.GetGrid().GetY() == targetY; });
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
    for (int x = 0; x < COL; x++)
    {
        for (int y = 0; y < ROW; y++)
        {
            Grid grid(x, y, panelNums.at(x + y * ROW));
            Panel panel(grid);
            board.push_back(panel);
        }
    }
}

void Board::Show()
{
    for (int x = 0; x < COL; x++)
    {
        for (int y = 0; y < ROW; y++)
        {
            std::cout.width(2); // 可視性を上げる
            std::cout << this->GetPanelByCoord(x, y).ToString() << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::MovePanel(MoveDirection direction)
{
    auto hiddenPanelIter = std::find_if(board.begin(), board.end(), [](Panel p)
                                        { return p.IsHidden(); });
    auto changePanelIter = this->GetPanelIterByDirection(*hiddenPanelIter, direction);

    // FIXME: 座標情報がおかしいため正しく動作していない（うまく座標更新できていない？）
    // DEBUG
    std::cout << "hidden: " << hiddenPanelIter->GetGrid().GetNum() << "(" << hiddenPanelIter->GetGrid().GetX() << ",";
    std::cout << hiddenPanelIter->GetGrid().GetY() << "), change: " << changePanelIter->GetGrid().GetNum();
    std::cout << "(" << changePanelIter->GetGrid().GetX() << "," << changePanelIter->GetGrid().GetY() << ")" << std::endl;
    // DEBUG

    std::iter_swap(hiddenPanelIter, changePanelIter);
    hiddenPanelIter->SwapPanel(*changePanelIter);
}
