QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit_debit.cpp \
    kayttoliittyma.cpp \
    main.cpp \
    mainwindow.cpp \
    nosto.cpp \
    nostomuu.cpp \
    pinni.cpp \
    saldo.cpp \
    tilitapahtumat.cpp \
    vaihdapin.cpp

HEADERS += \
    credit_debit.h \
    kayttoliittyma.h \
    mainwindow.h \
    nosto.h \
    nostomuu.h \
    pinni.h \
    saldo.h \
    tilitapahtumat.h \
    vaihdapin.h

FORMS += \
    credit_debit.ui \
    kayttoliittyma.ui \
    mainwindow.ui \
    nosto.ui \
    nostomuu.ui \
    pinni.ui \
    saldo.ui \
    tilitapahtumat.ui \
    vaihdapin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backgroundmain.qrc



win32: LIBS += -L$$PWD/pin_DLL/pin_DLL/build/debug/ -lpin_DLL

INCLUDEPATH += $$PWD/pin_DLL/pin_DLL
DEPENDPATH += $$PWD/pin_DLL/pin_DLL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/rest_api_ddl/build/release/ -lrest_api_ddl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/rest_api_ddl/build/debug/ -lrest_api_ddl
else:unix: LIBS += -L$$PWD/rest_api_ddl/build/ -lrest_api_ddl

INCLUDEPATH += $$PWD/rest_api_ddl
DEPENDPATH += $$PWD/rest_api_ddl
