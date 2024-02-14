#include <QDebug>
#include <algorithm>
#include "MainWindow.hpp"

MainWindow::MainWindow()
    : QObject(),
      _text("ゲームスタート！")
{
  _board.Initialize();
}

void MainWindow::MoveHiddenPanelToLeft()
{
  MoveHiddenPanel(MoveDirection::Left);
}

void MainWindow::MoveHiddenPanelToRight()
{
  MoveHiddenPanel(MoveDirection::Right);
}

void MainWindow::MoveHiddenPanelToUp()
{
  MoveHiddenPanel(MoveDirection::Up);
}

void MainWindow::MoveHiddenPanelToDown()
{
  MoveHiddenPanel(MoveDirection::Down);
}

void MainWindow::ResetGame()
{
  _board.Initialize();
  _text = "ゲームスタート！";
  emit PanelsChanged();
  emit TextChanged();
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

QVariantList MainWindow::GetPanels() const
{
  QVariantList list;
  for (auto value : _board.GetPanelsAsIntVector())
  {
    list.append(QVariant::fromValue(value));
  }

  return list;
}

void MainWindow::SetPanels(const QVariantList &list)
{
  // 画面から直接Boardを変更することは想定しないので実装しない
  // ただ、Signalは用意しないと落ちるっぽいので、シグネチャだけ用意しておく
}

void MainWindow::MoveHiddenPanel(MoveDirection direction)
{
  if (_board.IsSolved())
    return;

  _board.MovePanel(direction);
  if (_board.IsSolved())
  {
    _text = "パズル完成！おめでとう！";
  }
  emit PanelsChanged();
  emit TextChanged();
}
