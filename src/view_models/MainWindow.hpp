#pragma once
#include <QObject>
#include <QVariant>
#include <QString>
#include <vector>
#include "../models/Board.hpp"

class MainWindow : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString Text READ GetText WRITE SetText NOTIFY TextChanged)
  Q_PROPERTY(QVariantList DataList READ GetDataList WRITE SetDataList NOTIFY DataListChanged)

public:
  MainWindow();

  Q_INVOKABLE void MoveHiddenPanelToLeft();
  Q_INVOKABLE void MoveHiddenPanelToRight();
  Q_INVOKABLE void MoveHiddenPanelToUp();
  Q_INVOKABLE void MoveHiddenPanelToDown();
  Q_INVOKABLE void ResetGame();

  QString GetText() const;
  void SetText(const QString &text);
  QVariantList GetDataList() const;
  void SetDataList(const QVariantList &list);

signals:
  void TextChanged();
  void DataListChanged();

private:
  Board board;
  QString _text;
  std::vector<int> _dataList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
};
