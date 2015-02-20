TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    save_load.cpp \
    atoms.cpp \
    lib.cpp \
    integrator.cpp \
    unitconverter.cpp \
    potential.cpp \
    list/list.cpp \
    sample.cpp \
    list/neighborlist.cpp


HEADERS += \
    save_load.h \
    atoms.h \
    lib.h \
    integrator.h \
    unitconverter.h \
    potential.h \
    list/list.h \
    sample.h \
    list/neighborlist.h

