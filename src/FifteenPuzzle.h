#pragma once
#include "Board.h"
#include <GLFW/glfw3.h>

class FifteenPuzzle
{
private:
	Board board;
	FifteenPuzzle();
	FifteenPuzzle(const FifteenPuzzle &) = delete;
	FifteenPuzzle &operator=(const FifteenPuzzle &) = delete;
	static void handleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void reshape(GLFWwindow *window, int width, int height);
	static void drawGrid();

public:
	static FifteenPuzzle &GetInstance();
	void Run();
};
