import QtQuick 2.0

Item {
    id: root
    width: 60; height: 60

    Rectangle {
        id: page
        color: settings.color

        Image {
            id: restartImg
            width: 60; height: 60
            source: "qrc:images/restart.png"

            MouseArea {
                anchors.fill: parent
                onClicked: settings.restart()
            }
        }
    }
}
