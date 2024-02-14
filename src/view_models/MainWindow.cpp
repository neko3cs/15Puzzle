#include <QDebug>
#include <algorithm>
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

QVariantList MainWindow::GetDataList() const
{
  QVariantList list;
  for (auto value : _dataList)
  {
    list.append(QVariant::fromValue(value));
  }

  return list;
}

void MainWindow::SetDataList(const QVariantList &list)
{
  std::vector<int> convedList;
  for (const QVariant &item : list)
  {
    if (item.canConvert<int>())
    {
      convedList.push_back(item.value<int>());
    }
    else
    {
      qWarning();
    }
  }

  bool listIsSame = _dataList.size() == convedList.size() &&
                    std::equal(_dataList.begin(), _dataList.end(), convedList.begin(), convedList.end());

  if (listIsSame)
  {
    _dataList = convedList;
    emit DataListChanged();
  }
}
