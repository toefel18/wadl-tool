TEMPLATE = lib

TARGET = json

CONFIG += static

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    json.h
	json-forwards.h

SOURCES += \
    jsoncpp.cpp
