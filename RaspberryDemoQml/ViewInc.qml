import QtQuick 2.0

Item {
    id: root
    width: parent.width; height: parent.height

    Rectangle {
        id: page
        color: settings.color
        width: parent.width; height: parent.height

        /*Restart {
            id: restartButton
            //anchors.top: parent.top
            //anchors.right: parent.right
        }*/

        Text {
            id: typeText
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.typeTextY
            font.pointSize: settings.typeTextS;
            text: settings.typeText
        }

        Image {
            id: typeImg
            width: settings.typeImgW; height: settings.typeImgH
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.typeImgY
            source: settings.typeImgSrc
        }

        Image {
            id: minus
            width: settings.minW; height: settings.minH
            //anchors.verticalCenter: page.verticalCenter
            x: settings.minX; y: settings.minY
            source: settings.minImg

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    settings.num = (settings.num <= 0) ? 0 : (settings.num - settings.interval)
                    settings.startTimeoutTimer()
                }
            }
        }

        Image {
            id: plus
            width: settings.plusW; height: settings.plusH
            //anchors.verticalCenter: page.verticalCenter
            x: settings.plusX; y: settings.plusY
            source: settings.plusImg

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    settings.num += settings.interval
                    settings.startTimeoutTimer()
                }
            }
        }

        Text {
            id: numText
            text: settings.numText
            //anchors.verticalCenter: page.verticalCenter
            anchors.horizontalCenter: page.horizontalCenter
            y: settings.numTextY
            font.pointSize: settings.numTextS
        }
    }
}
