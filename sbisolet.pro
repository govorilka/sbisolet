QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sbisolet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

INCLUDEPATH += src

HEADERS += \
        ui/mainwindow.h \
        ui/mycanvas.h \
        ui/qtsfmlcanvas.h \
        ui/settingsdialog.h \
        ui/command.h \

HEADERS += \
        src/terrain.h \
        src/precomp.h \
        src/Scene.h \
        src/Plane.h \
        src/Config.h \
        src/Camera.h \
        src/Bonuses.h \
        src/UI.h \
        src/GameObject.h \
        src/Segment.h \
        src/Utils.h \
        src/CollisionUtils.h

HEADERS += \
        src\Enemies\Balloon.h \
        src\Enemies\Enemies.h \
        src\Enemies\Kamikaze.h \
        src\Enemies\Cloud.h

SOURCES += \
        ui/main.cpp \
        ui/mainwindow.cpp \
        ui/mycanvas.cpp \
        ui/qtsfmlcanvas.cpp \
        ui/settingsdialog.cpp \
        ui/command.cpp \

SOURCES += \
        src/UI.cpp \
        src/terrain.cpp \
        src/Scene.cpp \
        src/Plane.cpp \
        src/Camera.cpp \
        src/Bonuses.cpp \
        src/GameObject.cpp \
        src/Segment.cpp \
        src/Utils.cpp \
        src/CollisionUtils.cpp

SOURCES += \
        src\Enemies\Balloon.cpp \
        src\Enemies\Enemies.cpp \
        src\Enemies\Kamikaze.cpp \
        src\Enemies\Cloud.cpp

FORMS += \
        ui/mainwindow.ui \
        ui/settingsdialog.ui 

RESOURCES += \
    sbisolet.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
