#-------------------------------------------------
#
# Project created by QtCreator 2014-09-21T13:01:35
#
#-------------------------------------------------



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp-data-binding-wadl
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

#INFO:
# http://wiki.codesynthesis.com/Using_XSD_with_Qt_Creator

INCLUDEPATH += "C:\xerces-c-3.1.1\src" \
               "C:\xsd-4.0.0-i686-windows\libxsd"

LIBS += -L"C:\xerces-c-3.1.1\src\.libs" \
        -lxerces-c

SOURCES += main.cpp\
        readablewadlwindow.cpp \
        wadl.cxx \
        xml.cxx

HEADERS  += readablewadlwindow.h \
         wadl.hxx \
         xml.hxx

FORMS    += readablewadlwindow.ui
