TEMPLATE = app
CONFIG += console
CONFIG += thread
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
QMAKE_LFLAGS += -pthread

SOURCES += \
    SendData.cpp \
    Beacon.cpp \
    make-sockaddr.cpp \
    main.cpp \
    Client.cpp \
    Server.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    SendData.h \
    Beacon.h \
    make-sockaddr.h \
    Heading.h \
    Client.h \
    Server.h

