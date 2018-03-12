import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    id : plateau
    width : 500
    height : 600
    color : "lightgray"


    Text {
        id : titre
        text : "Jeu du 2048"
        y : 30
        anchors.horizontalCenter: plateau.horizontalCenter
        font.pointSize: 30
        font.bold: true
        font.family : "Helvetica"

        MouseArea { id: mouseArea; anchors.fill: parent }

        states: State {
            name: "down"; when: mouseArea.pressed == true
            PropertyChanges { target: titre; y: 40; rotation: 30; color: "red" }
        }

        transitions: Transition {
            from: ""; to: "down"; reversible: true
            ParallelAnimation {
                NumberAnimation { properties: "y, rotation"; duration: 100; easing.type: Easing.InOutQuad }
                ColorAnimation { duration: 100 }
            }
        }

        Rectangle {
            id : jeu
            property alias taille : jeu.taille

            Grid {
                id: choix_taille
                anchors.horizontalCenter : jeu.horizontalCenter; anchors.top : jeu.top ; anchors.topMargin: 4
                rows: 1; columns: 4; spacing: 3

                Cell { Text {
                        id : taille3
                        text : 3
                        anchors.horizontalCenter : parent.horizontalCenter
                        anchors.verticalCenter : parent.verticalCenter
                    } cellColor: "white"; onClicked: jeu.taille = 3 }
                Cell { cellColor: "white"; onClicked: jeu.taille = 4 }
                Cell { cellColor: "white"; onClicked: jeu.taille = cellColor }
                Cell { cellColor: "white"; onClicked: jeu.taille = cellColor }

            }

        }





    }

}
