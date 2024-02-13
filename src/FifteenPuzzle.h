#pragma once
#include <string>
#include "Board.h"

class FifteenPuzzle
{
private:
	Board board;
	static constexpr int WindowWidth = 640;
	static constexpr int WindowHeight = 480;
	inline static const std::string FontPath = "/System/Library/Fonts/Helvetica.ttc";
	FifteenPuzzle();
	FifteenPuzzle(const FifteenPuzzle &) = delete;
	FifteenPuzzle &operator=(const FifteenPuzzle &) = delete;

public:
	static FifteenPuzzle &GetInstance();
	void RunAsCli();
};
