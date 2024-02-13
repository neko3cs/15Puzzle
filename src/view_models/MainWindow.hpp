#pragma once
#include <QObject>
#include <QString>
#include "../models/Board.hpp"

class MainWindow : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString Text READ GetText WRITE SetText NOTIFY TextChanged)

public:
  MainWindow();

  Q_INVOKABLE void MoveHiddenPanelToLeft();
  Q_INVOKABLE void MoveHiddenPanelToRight();
  Q_INVOKABLE void MoveHiddenPanelToUp();
  Q_INVOKABLE void MoveHiddenPanelToDown();
  Q_INVOKABLE void ResetGame();

  QString GetText() const;
  void SetText(const QString &text);

signals:
  void TextChanged();

private:
  Board board;
  QString _text;
};
