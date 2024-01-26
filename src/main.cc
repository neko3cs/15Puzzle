#include "FifteenPuzzle.h"
#include <iostream>

int main(int const argc, char const *argv[])
{
  if (argc == 2 && std::strcmp(argv[1], "--cli") == 0)
  {
    FifteenPuzzle::GetInstance().RunAsCli();
  }
  else
  {
    FifteenPuzzle::GetInstance().RunAsGui();
  }

  return 0;
}
