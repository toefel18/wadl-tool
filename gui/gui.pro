TEMPLATE = app

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    readablewadlwindow.cpp

HEADERS  += readablewadlwindow.h

FORMS    += readablewadlwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../wadl/release/ -lwadl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../wadl/debug/ -lwadl
else:unix: LIBS += -L$$OUT_PWD/../wadl/ -lwadl

INCLUDEPATH += $$PWD/../wadl
DEPENDPATH += $$PWD/../wadl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../json/release/ -ljson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../json/debug/ -ljson
else:unix: LIBS += -L$$OUT_PWD/../json/ -ljson

INCLUDEPATH += $$PWD/../json
DEPENDPATH += $$PWD/../json

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json/release/libjson.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json/debug/libjson.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json/release/json.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json/debug/json.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../json/libjson.a
