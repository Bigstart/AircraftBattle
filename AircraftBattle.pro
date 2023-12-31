QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    enemyplane.cpp \
    heroplane.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp

HEADERS += \
    bullet.h \
    config.h \
    enemyplane.h \
    heroplane.h \
    mainscene.h \
    map.h


