TEMPLATE  = app
TARGET    = gui
QT       += core gui sql

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
    client.cpp \
    detailsticket.cpp \
    dialogcombobox.cpp \
    employe.cpp \
    erreur.cpp \
    gestionnairedialogue.cpp \
    gestionnairetickets.cpp \
    gestionnaireutilisateurs.cpp \
    gestionnairemessages.cpp \
    ingenieur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    messageinfosticket.cpp \
    technicien.cpp \
    ticket.cpp \
    ecranprincipal.cpp \
    utilisateur.cpp \
    creationticket.cpp \
    message.cpp \
    utilitaires.cpp \
    motifcloture.cpp

HEADERS += \
    client.h \
    detailsticket.h \
    dialogcombobox.h \
    employe.h \
    erreur.h \
    gestionnairedialogue.h \
    gestionnairetickets.h \
    gestionnaireutilisateurs.h \
    gestionnairemessages.h \
    ingenieur.h \
    mainwindow.h \
    messageinfosticket.h \
    technicien.h \
    ticket.h \
    utilisateur.h\
    login.h \
    mainwindow.h \
    ecranprincipal.h \
    creationticket.h \
    fabriqueidentifiant.h \
    message.h \
    utilitaires.h \
    motifcloture.h

FORMS += \
    detailsticket.ui \
    dialogcombobox.ui \
    erreur.ui \
    login.ui \
    mainwindow.ui \
    ecranprincipal.ui \
    creationticket.ui \
    messageinfosticket.ui \
    motifcloture.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
