#pragma once
#include <string>
#include "Board.h"
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

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
	static void HandleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void Reshape(GLFWwindow *window, int width, int height);
	static void DrawPanel(int x1, int y1, int x2, int y2);
	static void DrawGrid();
	GLFWwindow *InitGL();
	void LoadFont(FT_Library &library, FT_Face &face);
	void RenderText(FT_Face &face, const char *text, GLint x, GLint y);

public:
	static FifteenPuzzle &GetInstance();
	void Run();
};
