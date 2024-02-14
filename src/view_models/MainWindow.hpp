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
  Q_PROPERTY(QVariantList Panels READ GetPanels WRITE SetPanels NOTIFY PanelsChanged)

public:
  MainWindow();

  Q_INVOKABLE void MoveHiddenPanelToLeft();
  Q_INVOKABLE void MoveHiddenPanelToRight();
  Q_INVOKABLE void MoveHiddenPanelToUp();
  Q_INVOKABLE void MoveHiddenPanelToDown();
  Q_INVOKABLE void ResetGame();

  QString GetText() const;
  void SetText(const QString &text);
  QVariantList GetPanels() const;
  void SetPanels(const QVariantList &list);

signals:
  void TextChanged();
  void PanelsChanged();

private:
  Board _board;
  QString _text;
};
