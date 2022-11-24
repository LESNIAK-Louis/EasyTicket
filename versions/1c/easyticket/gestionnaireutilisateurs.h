#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H

#include "utilisateur.h"
#include "client.h"
#include <QMap>

class GestionnaireUtilisateurs
{
public:
    GestionnaireUtilisateurs();
    Utilisateur* getUtilisateur(QString login);

    ~GestionnaireUtilisateurs();

private:
    QMap<QString,Utilisateur*> utilisateurs;
};

#endif // GESTIONNAIREUTILISATEURS_H
