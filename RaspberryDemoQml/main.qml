/*import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: window
    visible: true
    visibility: "FullScreen"
    width: 640
    height: 480

    Button {
        text: "exit fullscreen"
        onClicked: window.visibility = "Windowed"
    }
}*/

/*import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    visibility: "FullScreen"
    width: 480
    height: 320
    //title: qsTr("Hello World")

    ApplicationFlow {
    }
}*/

import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: settings.screenW; height: settings.screenH
    visibility: "FullScreen"
    visible: true
    title: qsTr("Hello World")

    property alias state: page.state
    property alias page: page

    Rectangle {
        id: page
        width: parent.width; height: parent.height

        //property alias viewDoors: viewDoors

        ViewDoors {
            id: viewDoors; visible: false
            onClicked: {
                if (viewDoors.type === 1)
                page.state = "viewInc"
            }
        }

        ViewInc { id: viewInc; visible: false }

        /*viewDoors.onClicked: {
            if (viewDoors.type === 1)
                state = "viewInc"
        }*/

        state: "viewDoors"
        states: [
            State {
                name: "initial"
            },
            State {
                name: "viewDoors"
                PropertyChanges { target: viewDoors; visible: true }
                PropertyChanges { target: viewInc; visible: false }
            },
            State {
                name: "viewInc"
                PropertyChanges { target: viewDoors; visible: false }
                PropertyChanges { target: viewInc; visible: true }
            }
        ]
    }
}
