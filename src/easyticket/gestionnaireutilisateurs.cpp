#include "gestionnaireutilisateurs.h"

GestionnaireUtilisateurs::GestionnaireUtilisateurs()
{
    /*
    utilisateurs.insert("louis", new Client("louis", "Lesniak", "Louis"));
    utilisateurs.insert("theo", new Client("theo", "Joffroy", "Théo"));
    utilisateurs.insert("aboubacar", new Client("aboubacar", "Hassane Chekou Kore", "Aboubacar"));
    utilisateurs.insert("alexis", new Technicien("alexis", "Scheuer", "Alexis"));
    */
}

Utilisateur& GestionnaireUtilisateurs::getUtilisateur(QString login){

    return *(utilisateurs.value(login));
}

void GestionnaireUtilisateurs::ajouterUtilisateur(Utilisateur& u){

    if(!utilisateurs.contains(u.getLogin()))
        utilisateurs.insert(u.getLogin(), &u);
}

GestionnaireUtilisateurs::~GestionnaireUtilisateurs(){

    qDeleteAll(utilisateurs);
    utilisateurs.clear();
}
