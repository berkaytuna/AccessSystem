import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: 480; height: 320
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: page
        color: settings.color

        width: parent.width; height: parent.height

        Grid {
            id: grid
            anchors.horizontalCenter: parent.horizontalCenter
            y: settings.dY;
            rows: 1; columns: settings.rNum; spacing: settings.space
            Door { dName: settings.dOne; visible: settings.dNum !== 0 }
            Door { dName: settings.dTwo; visible: settings.dNum === 2 }
        }

        Text {
            id: text
            text: settings.text
            anchors.horizontalCenter: parent.horizontalCenter
            y: settings.textY
            font.pointSize: settings.textS
        }
    }
}
