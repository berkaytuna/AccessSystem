import QtQuick 2.0

Item {
    id: root
    width: parent.width; height: parent.height

    Rectangle {
        id: page
        color: settings.rColor
        width: parent.width; height: parent.height

        Image {
            id: rImg
            width: settings.rImgWidth; height: settings.rImgHeight
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.rImgY;
            source: settings.bSuccess ? "qrc:images/rTick.png" : "qrc:images/rCross.png"
        }

        Text {
            id: message
            text: settings.text
            font.pointSize: 16 // settings.dTextS;
            anchors.horizontalCenter: page.horizontalCenter
            y: 240 //settings.dTextY
        }
    }

}
