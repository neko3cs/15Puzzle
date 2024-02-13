#include <QDebug>
#include "MainWindow.hpp"

MainWindow::MainWindow()
    : QObject(),
      _text("ゲームスタート！")
{
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
