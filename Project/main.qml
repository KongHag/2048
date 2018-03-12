import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 640
    height: 800
    property alias repeater: repeater
    title: qsTr("Hello World")
    property int taille: 6
    property int tuile: 5

    Text {
        id: text1
        x: 260
        y: 39
        text: qsTr("2048")
        font.weight: Font.DemiBold
        font.family: "Monospace"
        verticalAlignment: Text.AlignTop
        topPadding: -2
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 60
    }

    Rectangle {
        id: rectangle
        color: "#cdcdcd"
        antialiasing: true
        border.color: "#bbbbbb"
        anchors.bottomMargin: 150
        anchors.topMargin: 150
        anchors.rightMargin: 70
        anchors.leftMargin: 70
        anchors.fill: parent
        radius:10

        Grid {
            id: gridfond
            x: 10+grid.spacing/2
            y: 10+grid.spacing/2
            width: 480
            height: 480
            spacing: 10
            rows: taille
            columns: taille
            horizontalItemAlignment: Grid.AlignHCenter
            verticalItemAlignment: Grid.AlignVCenter
            Repeater {
                id: repeaterfond
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                        model: taille*taille
                        delegate: Rectangle {
                            width: ((parent.width-taille*gridfond.spacing)/taille)
                            height: ((parent.height-taille*gridfond.spacing)/taille)
                            color: "#cbbeb1"
                            radius: 3

                        }
                    }
        }
        Grid {
            id: grid
            x: 10+grid.spacing/2
            y: 10+grid.spacing/2
            width: 480
            height: 480
            spacing: 10
            rows: taille
            columns: taille
            horizontalItemAlignment: Grid.AlignHCenter
            verticalItemAlignment: Grid.AlignVCenter
            Repeater {
                id: repeater
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                        model: taille*taille
                        delegate:  Rectangle {
                            width: (tuile==index)? ((parent.width-taille*grid.spacing)/taille): 0
                            height: (tuile==index)? ((parent.height-taille*grid.spacing)/taille): 0
                            color: "#ffffff"
                            radius: 3

                        }
                    }
        }
    }
}
