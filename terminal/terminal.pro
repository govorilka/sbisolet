QT += widgets serialport
requires(qtConfig(combobox))

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    triangle.cpp \
    glwidget.cpp \
    logo.cpp \
    window.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    triangle.h \
    glwidget.h \
    logo.h \
    window.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
