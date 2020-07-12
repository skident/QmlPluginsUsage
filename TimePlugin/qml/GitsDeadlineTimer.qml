import QtQuick 2.0
import QtQuick.Controls 2.0
import com.gits.time 1.0

GitsDeadlineTimerCpp {
    id: root

    property alias prefix: _prefix.text

    width: parent.width
    height: 40

    Column {
        spacing: 20

        Item {
            width: 200
            height: childrenRect.height

            Row {
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: _prefix

                    font.pixelSize: 20
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    id: input

                    font.pixelSize: 20
                    anchors.verticalCenter: parent.verticalCenter

                    horizontalAlignment: Text.AlignHCenter
                    text: root.timeElapsed
                }
            }
        }

        Button {
            id: timerController

            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 40

            text: root.isActive ? qsTr("Stop") : "Start"

            onClicked: {
                if (root.isActive)
                    root.pause();
                else
                    root.start();
            }

            onPressAndHold: {
                root.stop();
            }
        }
    }
}
