
import QtQuick 2.0

Item {
    id: container

    property alias taille: rectangle.text.text

    signal clicked(text taille)

    width: 40; height: 25



    Rectangle {
        id: rectangle
        border.color: "black"
        anchors.fill: parent
        Text {
            id : taille
            text : rectangle.text
            anchors.horizontalCenter : parent.horizontalCenter
            anchors.verticalCenter : parent.verticalCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked(container.text)
    }

}

