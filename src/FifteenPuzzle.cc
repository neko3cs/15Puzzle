#include "FifteenPuzzle.h"
#include <iostream>
#include <GLFW/glfw3.h>

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

void FifteenPuzzle::DrawGrid()
{
  glColor3f(0.0f, 0.0f, 0.0f);

  for (int i = 1; i < 6; i++)
  {
    glBegin(GL_LINES);
    glVertex2f(i, 1);
    glVertex2f(i, 5);
    glEnd();
  }
  for (int i = 1; i < 6; i++)
  {
    glBegin(GL_LINES);
    glVertex2f(1, i);
    glVertex2f(5, i);
    glEnd();
  }
}

FifteenPuzzle &FifteenPuzzle::GetInstance()
{
  static FifteenPuzzle instance;
  return instance;
}

void FifteenPuzzle::Run()
{
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return;
  }

  GLFWwindow *window = glfwCreateWindow(640, 480, "15 Puzzle", nullptr, nullptr);
  if (!window)
  {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 6, 0, 6, -1, 1);
  glMatrixMode(GL_MODELVIEW);

  glfwSetKeyCallback(window, HandleKeyboard);
  glfwSetWindowSizeCallback(window, Reshape);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();

    // board.Show(); // FIXME: GUIで実装する

    if (board.IsSolved())
    {
      // パズルが解けたら褒めて終了
      std::cout << "Congratulations! You solved puzzle!" << std::endl;
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
