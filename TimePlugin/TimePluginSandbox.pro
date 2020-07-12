TARGET = TimePlugin
QT += qml quick
CONFIG += c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.gits.time

DESTDIR = $$[QT_INSTALL_QML]/$$replace(uri, \., /)

# Input
SOURCES += \
        src/GitsDeadlineTimer.cpp \
        src/GitsTimer.cpp \
        src/TimePlugin_plugin.cpp \
        sandbox/main.cpp

HEADERS += \
        src/GitsDeadlineTimer.h \
        src/GitsTimer.h \
        src/TimePlugin_plugin.h

#https://groups.google.com/forum/#!msg/android-qt/fiXNLvfefW8/BBRvreDh2rkJ

RESOURCES += \
    sandbox/qml.qrc
