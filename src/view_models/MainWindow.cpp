#include <QDebug>
#include "MainWindow.hpp"

MainWindow::MainWindow()
    : QObject(),
      _text("ゲームスタート！")
{
}

void MainWindow::MoveHiddenPanelToLeft()
{
  qDebug() << "MainWindow::MoveHiddenPanelToLeft was called!!";
}

void MainWindow::MoveHiddenPanelToRight()
{
  qDebug() << "MainWindow::MoveHiddenPanelToRight was called!!";
}

void MainWindow::MoveHiddenPanelToUp()
{
  qDebug() << "MainWindow::MoveHiddenPanelToUp was called!!";
}

void MainWindow::MoveHiddenPanelToDown()
{
  qDebug() << "MainWindow::MoveHiddenPanelToDown was called!!";
}

void MainWindow::ResetGame()
{
  qDebug() << "MainWindow::ResetGame was called!!";
}

QString MainWindow::GetText() const
{
  return _text;
}

void MainWindow::SetText(const QString &text)
{
  if (text != _text)
  {
    _text = text;
    emit TextChanged();
  }
}
