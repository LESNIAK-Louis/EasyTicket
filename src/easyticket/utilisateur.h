#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "gestionnairetickets.h"

class Utilisateur {
protected:
    Utilisateur(QString login, QString nom, QString prenom);

public:
    bool estUnClient() const { return false; }
    bool estUnEmploye() const { return false; }
    bool estUnIngenieur() const { return false; }

    ~Utilisateur();

private:
    QString login;
    QString nom;
    QString prenom;
    GestionnaireTickets gestionnaireTickets;
};

#endif // UTILISATEUR_H
