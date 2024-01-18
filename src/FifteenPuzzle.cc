#include "FifteenPuzzle.h"
#include <iostream>
#include <GLFW/glfw3.h>

FifteenPuzzle::FifteenPuzzle()
{
  board.Initialize();
}

void FifteenPuzzle::handleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS || action == GLFW_REPEAT)
  {
    switch (key)
    {
    case GLFW_KEY_Q:
      std::cout << "Exit" << std::endl;
      glfwSetWindowShouldClose(window, GLFW_TRUE);
      break;
    case GLFW_KEY_LEFT:
      std::cout << "left key input!" << std::endl;
      // board.MovePanel(MoveDirection::Left);  // FIXME: staticメンバ関数だからインスタンスのメンバ変数を呼べない
      break;
    case GLFW_KEY_RIGHT:
      std::cout << "right key input!" << std::endl;
      // board.MovePanel(MoveDirection::Right);  // FIXME: staticメンバ関数だからインスタンスのメンバ変数を呼べない
      break;
    case GLFW_KEY_UP:
      std::cout << "up key input!" << std::endl;
      // board.MovePanel(MoveDirection::Up);  // FIXME: staticメンバ関数だからインスタンスのメンバ変数を呼べない
      break;
    case GLFW_KEY_DOWN:
      std::cout << "down key input!" << std::endl;
      // board.MovePanel(MoveDirection::Down);  // FIXME: staticメンバ関数だからインスタンスのメンバ変数を呼べない
      break;
    default:
      std::cout << "Invalid character was inputted: " << glfwGetKeyName(key, scancode) << std::endl;
      break;
    }
  }
}

void FifteenPuzzle::reshape(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 6, 0, 6, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void FifteenPuzzle::drawGrid()
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

  glfwSetKeyCallback(window, handleKeyboard);
  glfwSetWindowSizeCallback(window, reshape);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();

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
