
QT += core gui
QT += multimedia
QT += multimediawidgets
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    door.cpp \
    enemy.cpp \
    enemy2.cpp \
    health.cpp \
    losswindow.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    powerup.cpp \
    winwindow.cpp

HEADERS += \
    bullet.h \
    door.h \
    enemy.h \
    enemy2.h \
    health.h \
    losswindow.h \
    mainwindow.h \
    player.h \
    powerup.h \
    winwindow.h

FORMS += \
    losswindow.ui \
    mainwindow.ui \
    player.ui \
    winwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../../../Qt/6.3.2/sha1s.txt \
    ../projectresourse/Bricks.png \
    ../projectresourse/asset3/1 Characters/1 Biker/Attack.png \
    ../projectresourse/house1.png \
    ../projectresourse/map.txt \
    ../projectresourse/road_0.png

RESOURCES += \
    sounds.qrc \
    sounds.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Qt/6.4.1/mingw_64/lib/ -lQt6Multimedia
else:unix: LIBS += -L$$PWD/../../../../../Qt/6.4.1/mingw_64/lib/ -lQt6Multimedia

INCLUDEPATH += $$PWD/../../../../../Qt/6.4.1/mingw_64/include
DEPENDPATH += $$PWD/../../../../../Qt/6.4.1/mingw_64/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Qt/6.4.1/mingw_64/lib/ -lQt6MultimediaWidgets
else:unix: LIBS += -L$$PWD/../../../../../Qt/6.4.1/mingw_64/lib/ -lQt6MultimediaWidgets

INCLUDEPATH += $$PWD/../../../../../Qt/6.4.1/mingw_64/include
DEPENDPATH += $$PWD/../../../../../Qt/6.4.1/mingw_64/include

