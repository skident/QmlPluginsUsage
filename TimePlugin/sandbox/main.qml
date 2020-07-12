import QtQuick 2.12
import QtQuick.Controls 2.5

import com.gits.time 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Plugin Sandbox")

    GitsTimer {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 100

        prefix: "Timer: "
    }

    GitsDeadlineTimer {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 100

        prefix: "Deadline Timer: "
        secondsToEvent: 12
    }
}
