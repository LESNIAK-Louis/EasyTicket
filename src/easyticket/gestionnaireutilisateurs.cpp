#include "gestionnaireutilisateurs.h"

GestionnaireUtilisateurs::GestionnaireUtilisateurs()
{
    /*
    utilisateurs.insert("louis", new Client("louis", "Louis", "Lesniak"));
    utilisateurs.insert("theo", new Client("theo", "Théo", "Joffroy"));
    utilisateurs.insert("aboubacar", new Client("aboubacar", "Aboubacar", "Hassane Chekou Kore"));
    */
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateur(QString login){

    return utilisateurs.value(login);
}
