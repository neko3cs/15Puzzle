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
	static void HandleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void Reshape(GLFWwindow *window, int width, int height);
	static void DrawGrid();

public:
	static FifteenPuzzle &GetInstance();
	void Run();
};
