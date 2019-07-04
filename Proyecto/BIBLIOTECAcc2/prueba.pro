#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T11:22:51
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prueba
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    libro.cpp \
        main.cpp \
        prueba.cpp\
        MainWindow.cpp \
    DuLibro.cpp \
    DuAutor.cpp \
    DuEditorial.cpp \
    DuEntidadBase.cpp \
    DuCreadorBaseDeDatos.cpp \
    DuAltaLibroForm.cpp \
    DuAltaAutorForm.cpp \
    DuFormBase.cpp \
    DuSelectorDialog.cpp \
    DuAltaEditorialForm.cpp \
    DuBajaForm.cpp \
    DuConsultaForm.cpp \
    DuConsultaLibroForm.cpp \
    DuModificacionForm.cpp \
    DuModificacionLibroForm.cpp\
    modobibliotecario.cpp \
    modoestudiante.cpp

HEADERS += \
    libro.h \
        prueba.h\
        MainWindow.h \
    DuLibro.h \
    DuAutor.h \
    DuEditorial.h \
    DuEntidadBase.h \
    DuCreadorBaseDeDatos.h \
    DuAltaLibroForm.h \
    DuAltaAutorForm.h \
    DuFormBase.h \
    DuSelectorDialog.h \
    DuAltaEditorialForm.h \
    DuBajaForm.h \
    DuConsultaForm.h \
    DuConsultaLibroForm.h \
    DuModificacionForm.h \
    DuModificacionLibroForm.h\
    modobibliotecario.h \
    modoestudiante.h

FORMS += \
        prueba.ui\
        MainWindow.ui \
    DuAltaLibroForm.ui \
    DuAltaAutorForm.ui \
    DuSelectorDialog.ui \
    DuAltaEditorialForm.ui \
    DuBajaForm.ui \
    DuConsultaForm.ui \
    DuConsultaLibroForm.ui \
    DuModificacionForm.ui \
    DuModificacionLibroForm.ui\
    modobibliotecario.ui \
    modoestudiante.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iconos.qrc
