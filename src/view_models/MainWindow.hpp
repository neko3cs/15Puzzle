#pragma once
#include <QObject>
#include <QString>

class MainWindow : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString Text READ GetText WRITE SetText NOTIFY TextChanged)

public:
  MainWindow();

  Q_INVOKABLE void ResetGame();

  QString GetText() const;
  void SetText(const QString &text);

signals:
  void TextChanged();

private:
  QString _text;
};
