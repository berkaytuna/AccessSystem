import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    width: 480
    height: 320

    color: "#8B0000"
    states: [
        State {
            name: "initial"
        }
    ]

    state: initial

    /*Image {
        id: image1
        source: "images/door.png"
        x: 50
        y: 60
        width: 150
        height: 150
    }*/
    Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            spacing: 5

            Image { source: "images/door.png"
                        width: 50; height: 50
                        Text { anchors.centerIn: parent
                               font.pointSize: 24; text: "Books" } }
            Rectangle { color: "gold"; radius: 10.0
                        width: 300; height: 50
                        Text { anchors.centerIn: parent
                               font.pointSize: 24; text: "Music" } }
            Rectangle { color: "lightgreen"; radius: 10.0
                        width: 300; height: 50
                        Text { anchors.centerIn: parent
               }
        }
    }
}
