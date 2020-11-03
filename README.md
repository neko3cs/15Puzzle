# 15Puzzle

学生の時に作ったコードが出てきたので GitHub に保存。

そのうち動くようにする。

## 設計メモ

- Boardクラスを作る
    - BoardクラスはUI層のクラスとして定義し、コードテストしない
    - 初期化はBoardクラスから行い、ゲームの進行、制御はBoardManagerに任せる
    - BoardManagerはコードテストする
