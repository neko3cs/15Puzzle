#include "BoardManager.h"

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
            cout.width(2); //可視性を上げる
            cout << boardManager.GetBoard()[i * boardManager.GetRow() + j].GetGrid().GetNum() << ' ';
        }
        cout << endl;
    }
}
