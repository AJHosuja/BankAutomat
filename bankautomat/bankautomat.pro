QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pinni.cpp

HEADERS += \
    mainwindow.h \
    pinni.h

FORMS += \
    mainwindow.ui \
    pinni.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backgroundmain.qrc



win32: LIBS += -L$$PWD/pin_DLL/pin_DLL/build/debug/ -lpin_DLL

INCLUDEPATH += $$PWD/pin_DLL/pin_DLL
DEPENDPATH += $$PWD/pin_DLL/pin_DLL
