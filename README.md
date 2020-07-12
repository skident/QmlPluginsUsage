# QmlPluginsUsage
A sample of creating custom QML plugin, deploy it and use

## TimePlugin
The main purpose of this project - it is a QML plugin which consists of C++ code, qmldir file and folder with qml files.

Each QML application has a list of directories where it searches for plugins and other resources. A path to QML plugins folder for a specific platform is stored in a QMAKE variable $$[QT_INSTALL_QML]. On my machine this variable is set to `/Users/skident/Qt5.14.2/5.14.2/clang_64/qml` for macos platform.

`deployment.pri` - is a qmake include file which invoke the `deployment.py` script. Firstly, I the command for deployment were inside this file, but working in qmake with shell commands is not a piece of cake, on the other hand a python script is easy to maintain and understand. 

`deployment.py` - that is a script which deploys plugin resources to the _$$[QT_INSTALL_QML]_ folder. I guess this script will be modified soon as for now it works only with qml folder and qmldir.

## App
The application which uses the TimePlugin. 
Usage of the TimePlugin is in main.qml. First of all we need to import this plugin any other module in QML
`import com.gits.time 1.0`

Then use available components
```GitsTimer {
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
```

