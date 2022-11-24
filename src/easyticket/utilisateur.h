#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "gestionnairetickets.h"

class Utilisateur {
protected:
    Utilisateur(QString login, QString nom, QString prenom);

public:
    virtual bool estUnClient() const = 0;
    virtual bool estUnEmploye() const = 0;
    virtual bool estUnIngenieur() const = 0;

    ~Utilisateur();

private:
    QString login;
    QString nom;
    QString prenom;
    GestionnaireTickets gestionnaireTickets;
};

#endif // UTILISATEUR_H
