import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 640
    height: 800
    property alias repeater: repeater
    title: qsTr("Hello World")

    FontLoader {
           id: webfont
           name: "Clear"
           source: "ClearSans-Medium.ttf"
       }

    property int taille: 4
    property var tuiles: [0,2,4,8,0,16,0,128,256,0,1024,2048,2,0,8,0]
    property var couleurs: ["#cbbeb1" ,	"#B339E8" ,	"#A0F773", 	"#F5ED71" ,	"#532DFE" ,	"#604276", 	"#82ACC8", 	"#5694E0", 	"#8E66BE", 	"#801BE1", 	"#941E79", 	"#5FBFC8"]

    function log2(a){
        return Math.max((Math.log(a)/Math.log(2)),0)
    }


    Text {
        id: text1
        x: 260
        y: 39
        text: qsTr("2048")
        font.weight: Font.DemiBold
        font.family: "clear"
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
                            width: ((parent.width-taille*grid.spacing)/taille)
                            height: ((parent.height-taille*grid.spacing)/taille)
                            color: couleurs[log2(tuiles[index])]
                            radius: 3
                            Text{
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.verticalCenter: parent.verticalCenter
                                text:tuiles[index]
                                font.pixelSize:50
                                opacity: (tuiles[index]!=0)
                            }
                        }
                    }
        }
    }
}
