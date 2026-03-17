QT -= gui
CONFIG += console c++17
CONFIG -= app_bundle
TEMPLATE = app
TARGET = CheckOutTests

INCLUDEPATH += .
INCLUDEPATH += $$PWD/googletest-main/googletest-main/googletest/include
INCLUDEPATH += $$PWD/googletest-main/googletest-main/googletest

SOURCES += \
    test.cpp \
    CheckOut.cpp \
    googletest-main/googletest-main/googletest/src/gtest-all.cc

HEADERS += \
    CheckOut.h \
    pch.h

DEFINES += GTEST_HAS_PTHREAD=0