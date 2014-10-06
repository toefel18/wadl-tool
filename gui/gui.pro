TEMPLATE = app

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    readablewadlwindow.cpp

##REFACTOR THIS INTO THE wadl SUBPROJECT only
INCLUDEPATH += "C:\xerces-c-3.1.1\src" \
               "C:\xsd-4.0.0-i686-windows\libxsd"

##TODO REFACTOR THIS INTO THE wadl SUBPROJECT only
LIBS += -L"C:\xerces-c-3.1.1\src\.libs" \
        -lxerces-c

HEADERS  += readablewadlwindow.h

FORMS    += readablewadlwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../wadl/release/ -lwadl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../wadl/debug/ -lwadl
else:unix: LIBS += -L$$OUT_PWD/../wadl/ -lwadl

INCLUDEPATH += $$PWD/../wadl
DEPENDPATH += $$PWD/../wadl
