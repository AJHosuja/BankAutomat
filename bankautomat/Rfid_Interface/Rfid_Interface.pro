QT -= gui

TEMPLATE = lib
DEFINES += RFID_INTERFACE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    rfid_engine.cpp \
    rfid_interface.cpp

HEADERS += \
    Rfid_Interface_global.h \
    rfid_engine.h \
    rfid_interface.h

QT += serialport

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

