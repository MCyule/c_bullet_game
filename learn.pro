QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    component/animatedspritecomponent.cpp \
    component.cpp \
    component/healthcomponent.cpp \
    component/motioncomponent.cpp \
    entity/card.cpp \
    entity/dotenemy.cpp \
    entity/enemy.cpp \
    entity/player.cpp \
    gameobject.cpp \
    globals.cpp \
    main.cpp \
    main/gameview.cpp \
    mainwindow.cpp \
    scene/hud.cpp \
    spell/modifyspell.cpp \
    spell/motionpath.cpp \
    spell/normalprojectile.cpp \
    spell/normalspell.cpp \
    spell/projectile.cpp \
    spell/projectileconfig.cpp \
    spell/spell.cpp

HEADERS += \
    component/animatedspritecomponent.h \
    component.h \
    component/healthcomponent.h \
    component/motioncomponent.h \
    entity/card.h \
    entity/dotenemy.h \
    entity/enemy.h \
    entity/player.h \
    gameobject.h \
    globals.h \
    main/gameview.h \
    mainwindow.h \
    scene/hud.h \
    spell/modifyspell.h \
    spell/motionpath.h \
    spell/normalprojectile.h \
    spell/normalspell.h \
    spell/projectile.h \
    spell/projectileconfig.h \
    spell/spell.h

FORMS += \
    mainwindow.ui \
    scene/hud.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
