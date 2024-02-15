import QtQuick
import QtQuick.Controls

ApplicationWindow {
  title: "15 Puzzle"
  width: 640
  height: 480
  visible: true
  background: Rectangle {
    color: "white"
  }

  Column {
    anchors.centerIn: parent
    spacing: 10
    focus: true
    Keys.onLeftPressed: mainWindow.MoveHiddenPanelToLeft()
    Keys.onRightPressed: mainWindow.MoveHiddenPanelToRight()
    Keys.onUpPressed: mainWindow.MoveHiddenPanelToUp()
    Keys.onDownPressed: mainWindow.MoveHiddenPanelToDown()

    Label {
      text: "15 Puzzle"
      font.pixelSize: 48
      color: "black"
      anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
      text: mainWindow.Text
      font.pixelSize: 24
      color: "black"
      anchors.horizontalCenter: parent.horizontalCenter
    }

    Grid {
      columns: 4
      rows: 4
      spacing: 5
      anchors.horizontalCenter: parent.horizontalCenter

      Repeater {
        model: mainWindow.Panels
        delegate: Rectangle {
          width: 50
          height: 50
          color: modelData == 16 ? "green" : "white"
          border.color: modelData == 16 ? "transparent" : "green"

          Text {
            text: modelData == 16 ? "" : modelData
            font.pixelSize: 36
            color: "black"
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
          }
        }
      }
    }

    Row {
      spacing: 5
      anchors.horizontalCenter: parent.horizontalCenter

      Button {
        text: "リセット"
        width: 120
        onClicked: mainWindow.ResetGame()
      }

      Button {
        text: "終了"
        width: 120
        onClicked: Qt.quit()
      }
    }

    Label {
      text: "方向キーでパネルを移動させて、パズルを揃えよう！"
      font.pixelSize: 16
      color: "black"
      anchors.horizontalCenter: parent.horizontalCenter
    }
  }
}