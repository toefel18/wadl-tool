TEMPLATE = lib
TARGET = wadl

CONFIG += static

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += "C:\xerces-c-3.1.1\src" \
               "C:\xsd-4.0.0-i686-windows\libxsd"

LIBS += -L"C:\xerces-c-3.1.1\src\.libs" \
        -lxerces-c

SUBDIRS = model

HEADERS += \
    wadl.hxx \
    xml.hxx \
    modelparser.h

SOURCES += \
    wadl.cxx \
    xml.cxx \
    modelparser.cpp
