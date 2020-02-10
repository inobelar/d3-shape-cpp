TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include($$PWD/src/d3_shape.pri)

SOURCES += \
        main.cpp \
