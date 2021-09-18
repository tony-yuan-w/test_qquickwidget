import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Rectangle {
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480
    //title: qsTr("Spix Example")
    color: "#ffffff"

    signal onclose()

    ColumnLayout {
        anchors.fill: parent
        spacing: 30

        anchors {
            top: parent.top
            left: parent.left
            topMargin: 5
            leftMargin: 5
        }

        GridLayout{
            columns: 2
            rows: 2

            Label{
                text:"server name"
            }
            TextField{
                objectName:"url"
            }

            Label{
                text:"server port"
            }
            TextField{
                objectName: "url1"
            }

            Label{
                text:"input 1"
            }

            TextField{

            }

            Label{
                text:"input 2"
            }

            TextField{

            }

        }

        Row{
            spacing: 100
            Button {
                objectName: "Button_Ok"
                text: "Press ok"
                onClicked: {
                    console.info("##################Button_Ok was clicked#################")
                }
            }
            Button {
                objectName: "Button_Cancel"
                text: "Close"
                onClicked: {
                    onclose()
                }
            }
        }

    }
}
