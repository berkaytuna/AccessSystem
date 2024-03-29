import QtQuick 2.0

Item {
    id: root
    width: settings.dWidth; height: settings.dHeight

    //property alias name: name.text
    property int type: 0
    signal clicked()

    Rectangle {
        id: page
        color: settings.dColor
        anchors.fill: parent

        Text {
            id: name
            font.pointSize: settings.dTextS;
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.dTextY
            text: root.type ? "massage" : "solarium"
        }

        Image {
            id: image
            width: settings.dImgWidth; height: settings.dImgHeight
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.dImgY;
            source: root.type ? "qrc:images/massage.png"
                              : "qrc:images/solarium.png"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.clicked()
            }
        }
    }
}
