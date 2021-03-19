import QtQuick 2.0

Item {
    id: root
    width: parent.width; height: parent.height

    property int type: 0
    signal clicked()

    Rectangle {
        id: page
        color: settings.color
        width: parent.width; height: parent.height

        Grid {
            id: grid
            anchors.horizontalCenter: parent.horizontalCenter
            y: settings.dY;
            rows: 1; columns: settings.dNum; spacing: settings.space
            Door {
                id: doorOne
                type: 0
                name: settings.dOne; /* type: settings.dTypeOne;*/ visible: settings.dNum !== 0
                onClicked: { root.type = type; root.clicked() } //visible = (type === 1) ? true : false
            }
            Door {
                id: doorTwo
                type: 1
                name: settings.dTwo; /*type: settings.dTypeTwo;*/ visible: settings.dNum === 2
                onClicked: { root.type = type; root.clicked() } //visible = (type === 1) ? true : false
            }
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
