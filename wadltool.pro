TARGET = wadltool
TEMPLATE = subdirs

QMAKE_CXXFLAGS += -std=c++11

SUBDIRS = \
    wadl \
    gui \
    json

gui.depends = wadl \
            json

