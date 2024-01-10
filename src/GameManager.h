#pragma once
#include "Board.h"

class GameManager
{
private:
    Board board;
    void ShowBoard();

public:
    GameManager();
    void Run();
};
