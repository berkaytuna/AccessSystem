import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: 480; height: 320
    visible: true
    title: qsTr("Hello World")

    property alias state: page.state
    property alias page: page

    Rectangle {
        id: page
        width: parent.width; height: parent.height

        property alias viewDoors: viewDoors

        ViewDoors { id: viewDoors; visible: false }
        ViewInc { id: viewInc; visible: false }

        viewDoors.onClicked: {
            if (viewDoors.type === 1)
                state = "viewInc"
        }

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
