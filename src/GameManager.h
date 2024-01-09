#pragma once
#include "BoardManager.h"

class GameManager
{
private:
    BoardManager boardManager;
    void ShowBoard();

public:
    GameManager();
    void Run();
};
