import QtQuick 2.0

Item {
    id: container
    width: settings.dWidth; height: settings.dHeight

    property alias dName: dName.text

    Rectangle {
        id: rectangle
        color: settings.dColor;
        anchors.fill: parent

        Text {
            id: dName
            font.pointSize: settings.dTextS;
            anchors.horizontalCenter: rectangle.horizontalCenter
            y: settings.dTextY
        }

        Image {
            width: settings.dImgWidth; height: settings.dImgHeight
            anchors.horizontalCenter: rectangle.horizontalCenter
            y: settings.dImgY;
            source: settings.dImg
        }
    }
}
