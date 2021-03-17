import QtQuick 2.0

Item {
    id: root
    width: parent.width; height: parent.height

    Rectangle {
        id: page
        color: settings.color
        width: parent.width; height: parent.height

        Image {
            id: minus
            width: settings.minW; height: settings.minH
            anchors.verticalCenter: page.verticalCenter
            x: settings.minX
            source: settings.minImg

            MouseArea {
                anchors.fill: parent
                onClicked: settings.num -= settings.interval
            }
        }

        Image {
            id: plus
            width: settings.plusW; height: settings.plusH
            anchors.verticalCenter: page.verticalCenter
            x: settings.plusX
            source: settings.plusImg

            MouseArea {
                anchors.fill: parent
                onClicked: settings.num += settings.interval
            }
        }

        Text {
            id: numText
            text: settings.numText
            anchors.verticalCenter: page.verticalCenter
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: settings.numTextS
        }
    }
}
