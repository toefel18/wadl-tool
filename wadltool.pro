TARGET = wadltool
TEMPLATE = subdirs

QMAKE_CXXFLAGS += -std=c++11

SUBDIRS = \
    wadl \
    gui

gui.depends = wadl

#INFO:
# http://wiki.codesynthesis.com/Using_XSD_with_Qt_Creator

