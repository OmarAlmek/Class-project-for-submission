
QT += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    enemy.cpp \
    health.cpp \
    main.cpp \
    player.cpp \
    powerup.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    health.h \
    player.h \
    powerup.h

FORMS += \
    player.ui

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

