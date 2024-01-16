#include "FifteenPuzzle.h"
#include <iostream>
#include <GLUT/glut.h>

void drawGrid()
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

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  glFlush();
}

void reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 6, 0, 6);
  glMatrixMode(GL_MODELVIEW);
}

void handleKeyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'q':
    std::cout << "Exit" << std::endl;
    std::exit(EXIT_SUCCESS);
    break;
  default:
    std::cout << "Invalid character was inputted: " << key << std::endl;
    break;
  }
}

void handleSpecialKey(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_LEFT:
    std::cout << "left key input!" << std::endl;
    break;
  case GLUT_KEY_RIGHT:
    std::cout << "right key input!" << std::endl;
    break;
  case GLUT_KEY_UP:
    std::cout << "up key input!" << std::endl;
    break;
  case GLUT_KEY_DOWN:
    std::cout << "down key input!" << std::endl;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

void initGL()
{
  const auto windowWidth = 640;
  const auto windowHeight = 480;
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(
      (glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2,
      (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
  glutCreateWindow("15 Puzzle");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(handleKeyboard);
  glutSpecialFunc(handleSpecialKey);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  initGL();
  glutMainLoop();

  FifteenPuzzle fifteenPuzzle;
  fifteenPuzzle.Run();

  return 0;
}
