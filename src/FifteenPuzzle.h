#pragma once
#include "Board.h"
#include <GLFW/glfw3.h>

class FifteenPuzzle
{
private:
	Board board;
	static constexpr int WindowWidth = 640;
	static constexpr int WindowHeight = 480;
	FifteenPuzzle();
	FifteenPuzzle(const FifteenPuzzle &) = delete;
	FifteenPuzzle &operator=(const FifteenPuzzle &) = delete;
	static void HandleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void Reshape(GLFWwindow *window, int width, int height);
	static void DrawPanel(int x1, int y1, int x2, int y2);
	static void DrawGrid();

public:
	static FifteenPuzzle &GetInstance();
	void Run();
};
