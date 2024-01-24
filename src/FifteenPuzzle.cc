#include "FifteenPuzzle.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

FifteenPuzzle::FifteenPuzzle()
{
  board.Initialize();
}

void FifteenPuzzle::HandleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS || action == GLFW_REPEAT)
  {
    const char *keyName = glfwGetKeyName(key, scancode);
    if (keyName || key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT || key == GLFW_KEY_UP || key == GLFW_KEY_DOWN)
    {
      switch (key)
      {
      case GLFW_KEY_Q:
        std::cout << "ゲームを終了します。" << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        break;
      case GLFW_KEY_LEFT:
        std::cout << "左キーが入力されました。" << std::endl;
        GetInstance().board.MovePanel(MoveDirection::Left);
        break;
      case GLFW_KEY_RIGHT:
        std::cout << "右キーが入力されました。" << std::endl;
        GetInstance().board.MovePanel(MoveDirection::Right);
        break;
      case GLFW_KEY_UP:
        std::cout << "上キーが入力されました。" << std::endl;
        GetInstance().board.MovePanel(MoveDirection::Up);
        break;
      case GLFW_KEY_DOWN:
        std::cout << "下キーが入力されました。" << std::endl;
        GetInstance().board.MovePanel(MoveDirection::Down);
        break;
      default:
        std::cout << "無効な文字が入力されました。: " << keyName << std::endl;
        break;
      }
    }
    else
    {
      std::cout << "無効なキーが入力されました。" << std::endl;
    }
  }
}

void FifteenPuzzle::Reshape(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 6, 0, 6, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void FifteenPuzzle::DrawPanel(int x1, int y1, int x2, int y2)
{
  glLineWidth(3.0f);
  glBegin(GL_LINE_LOOP);
  glVertex2i(x1, y1);
  glVertex2i(x2, y1);
  glVertex2i(x2, y2);
  glVertex2i(x1, y2);
  glEnd();
}

// TODO: 多分Boardクラスの責務
void FifteenPuzzle::DrawGrid()
{
  glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
  constexpr int startCoordX = 160;
  constexpr int startCoordY = 30;
  constexpr int panelSize = 80;
  for (auto row = 0; row < 4; row++)
  {
    for (auto col = 0; col < 4; col++)
    {
      DrawPanel(
          startCoordX + row * panelSize,
          startCoordY + col * panelSize,
          startCoordX + row * panelSize + panelSize,
          startCoordY + col * panelSize + panelSize);
    }
  }
}

GLFWwindow *FifteenPuzzle::InitGL()
{
  if (!glfwInit())
  {
    std::cerr << "GLFWの初期化に失敗しました。" << std::endl;
    std::terminate();
  }
  GLFWwindow *window = glfwCreateWindow(WindowWidth, WindowHeight, "15 Puzzle", nullptr, nullptr);
  if (!window)
  {
    std::cerr << "GLFWウィンドウの作成に失敗しました。" << std::endl;
    glfwTerminate();
    std::terminate();
  }

  glfwMakeContextCurrent(window);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, WindowWidth, WindowHeight, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glfwSetKeyCallback(window, HandleKeyboard);
  glfwSetWindowSizeCallback(window, Reshape);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

  return window;
}

void FifteenPuzzle::LoadFont(FT_Library &library, FT_Face &face)
{
  if (FT_Init_FreeType(&library))
  {
    std::cerr << "FreeTypeの初期化に失敗しました。" << std::endl;
    std::terminate();
  }
  if (FT_New_Face(library, FontPath.c_str(), 0, &face))
  {
    std::cerr << "FreeType Faceの作成に失敗しました。" << std::endl;
    std::terminate();
  }
  FT_Set_Pixel_Sizes(face, 0, 48 /* px */);
}

FifteenPuzzle &FifteenPuzzle::GetInstance()
{
  static FifteenPuzzle instance;
  return instance;
}

void FifteenPuzzle::Run()
{
  auto *window = InitGL();
  FT_Library library;
  FT_Face face;
  LoadFont(library, face);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();

    // board.Show(); // FIXME: GUIで実装する

    if (board.IsSolved())
    {
      // パズルが解けたら褒めて終了
      std::cout << "おめでとうございます！パズルが解けました！" << std::endl;
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  FT_Done_Face(face);
  FT_Done_FreeType(library);
  glfwTerminate();
}
