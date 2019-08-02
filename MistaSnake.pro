QT += gui
QT += widgets

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = MistaSnake

LIBS += -L"$$PWD/libs/SFML/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "$$PWD/libs/SFML/include"
DEPENDPATH += "$$PWD/libs/SFML/include"

SOURCES += \
        main.cpp \
    Field.cpp \
    CellObject.cpp \
    Stone.cpp \
    Stone.cpp \
    Wall.cpp \
    Cell.cpp \
    Ground.cpp \
    SnakePart.cpp \
    SnakeHead.cpp \
    MainWindow.cpp

DISTFILES += \
        textures/wood.jpg \
        textures/stone.bmp \
        textures/wall.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Cell.h \
    Field.h \
    CellObject.h \
    Stone.h \
    Stone.h \
    Wall.h \
    Ground.h \
    SnakePart.h \
    SnakeHead.h \
    MainWindow.h

FORMS += \
    MainWindow.ui


