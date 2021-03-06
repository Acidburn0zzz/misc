######################################################################
# Automatically generated by qmake (2.01a) Wed Oct 29 12:24:26 2008
######################################################################

TEMPLATE = app
TARGET = expo
DEPENDPATH += .
INCLUDEPATH += ./libsha2
unix:LIBS += -L./libsha2 -lsha2
win32:LIBS += .\libsha2\libsha2.a

CONFIG += qt debug
QT += sql
DEFINES += DEBUG

DESTDIR = ./bin
MOC_DIR = ./moc
OBJECTS_DIR = ./obj

#Automatisation de la compilation de libsha2
system(cd libsha2 && make)

# Input
HEADERS += defaultsqlmodel.h \
           defaulttableview.h \
           mainwindow.h \
           modeleajoutupdate.h \
           modeleatelier.h \
           modelegestionatelier.h \
           tablegestionatelier.h \
           vueatelier.h \
           vuegestionatelier.h
SOURCES += defaultsqlmodel.cpp \
           defaulttableview.cpp \
           main.cpp \
           mainwindow.cpp \
           modeleajoutupdate.cpp \
           modeleatelier.cpp \
           modelegestionatelier.cpp \
           tablegestionatelier.cpp \
           vueatelier.cpp \
           vuegestionatelier.cpp
TRANSLATIONS += expo_science_en.ts
