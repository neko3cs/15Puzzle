#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <iostream>
#include "models/Board.hpp"
#include "view_models/MainWindow.hpp"

int RunAsCli();
int RunAsGui(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  if (argc == 2 && std::strcmp(argv[1], "--cli") == 0)
  {
    return RunAsCli();
  }
  else
  {
    return RunAsGui(argc, argv);
  }
}

int RunAsCli()
{
  Board board;
  board.Initialize();
  while (true)
  {
    board.Show();

    char input;
    std::cout << "隠れパネルの移動(Hキー: 左移動, Jキー: 上移動, Kキー: 下移動, Lキー: 右移動)、終了(qキー)、リセット(rキー): " << std::flush;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (input == 'q')
    {
      std::cout << "ゲームを終了します。" << std::endl;
      break;
    }
    if (input == 'r')
    {
      board.Initialize();
    }
    else if (input == 'h' || input == 'H')
    {
      board.MovePanel(MoveDirection::Left);
    }
    else if (input == 'l' || input == 'L')
    {
      board.MovePanel(MoveDirection::Right);
    }
    else if (input == 'j' || input == 'J')
    {
      board.MovePanel(MoveDirection::Up);
    }
    else if (input == 'k' || input == 'K')
    {
      board.MovePanel(MoveDirection::Down);
    }
    else
    {
      std::cout << "無効な文字が入力されました: " << input << std::endl;
    }

    if (board.IsSolved())
    {
      // パズルが解けたら褒めて終了
      std::cout << "おめでとうございます！パズルが解けました！" << std::endl;
      break;
    }
  }

  return 0; // EXIT_CODE
}

int RunAsGui(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

#if defined(Q_OS_MAC)
  QQuickStyle::setStyle("Material");
#endif

  MainWindow mainWindow; // engineの前にmainWindowを宣言しないとpropertyがnullだという実行時エラーが出る
  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("mainWindow", &mainWindow);
  QObject::connect(
      &engine,
      &QQmlApplicationEngine::objectCreationFailed,
      &app,
      []()
      { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);
  engine.load(QUrl(u"qrc:/MainWindow.qml"_qs));

  return app.exec();
}
