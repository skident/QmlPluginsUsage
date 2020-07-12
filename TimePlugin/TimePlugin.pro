TEMPLATE = lib
TARGET = TimePlugin
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.gits.time

DESTDIR = $$[QT_INSTALL_QML]/$$replace(uri, \., /)

# Input
SOURCES += \
        src/GitsDeadlineTimer.cpp \
        src/GitsTimer.cpp \
        src/TimePlugin_plugin.cpp

HEADERS += \
        src/GitsDeadlineTimer.h \
        src/GitsTimer.h \
        src/TimePlugin_plugin.h

DISTFILES = qmldir \
    qml/GitsDeadlineTimer.qml \
    qml/GitsTimer.qml

include(deploy/deployment.pri)

#https://groups.google.com/forum/#!msg/android-qt/fiXNLvfefW8/BBRvreDh2rkJ
