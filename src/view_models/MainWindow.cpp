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
  _board.MovePanel(MoveDirection::Left);
  emit PanelsChanged();
}

void MainWindow::MoveHiddenPanelToRight()
{
  _board.MovePanel(MoveDirection::Right);
  emit PanelsChanged();
}

void MainWindow::MoveHiddenPanelToUp()
{
  _board.MovePanel(MoveDirection::Up);
  emit PanelsChanged();
}

void MainWindow::MoveHiddenPanelToDown()
{
  _board.MovePanel(MoveDirection::Down);
  emit PanelsChanged();
}

void MainWindow::ResetGame()
{
  _board.Initialize();
  emit PanelsChanged();
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
