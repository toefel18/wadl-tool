TEMPLATE = lib
TARGET = wadl

CONFIG += dynamic

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += "C:\xerces-c-3.1.1\src" \
               "C:\xsd-4.0.0-i686-windows\libxsd" \
               "C:\boost_1_56_0"

LIBS += -L"C:\xerces-c-3.1.1\src\.libs" \
        -lxerces-c

HEADERS += \
    wadl.hxx \
    xml.hxx \
    modelparser.h \
    restapp.h \
    resource.h \
    method.h \
    httpmethod.h \
    param.h \
    wadlparseexception.h \
    pathhelper.h

SOURCES += \
    wadl.cxx \
    xml.cxx \
    modelparser.cpp \
    restapp.cpp \
    resource.cpp \
    method.cpp \
    httpmethod.cpp \
    param.cpp \
    wadlparseexception.cpp \
    pathhelper.cpp
