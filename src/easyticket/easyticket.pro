TEMPLATE  = app
TARGET    = gui
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    employe.cpp \
    ingenieur.cpp \
=======
    login.cpp \
>>>>>>> 0327b7e8dc0f614c9647309cdd3c519bd4b1e200
    main.cpp \
    mainwindow.cpp \
    technicien.cpp \
    utilisateur.cpp

HEADERS += \
<<<<<<< HEAD
    employe.h \
    ingenieur.h \
    mainwindow.h \
    technicien.h \
    utilisateur.h
=======
    login.h \
    mainwindow.h
>>>>>>> 0327b7e8dc0f614c9647309cdd3c519bd4b1e200

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
