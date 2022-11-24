#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H

#include "utilisateur.h"
#include "client.h"
#include <QMap>

class GestionnaireUtilisateurs
{
private:
    QMap<QString,Utilisateur*> utilisateurs;

public:
    GestionnaireUtilisateurs();

    Utilisateur* getUtilisateur(QString login);

    ~GestionnaireUtilisateurs();
};

#endif // GESTIONNAIREUTILISATEURS_H
