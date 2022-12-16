#include "gestionnaireutilisateurs.h"

Gestionnaire<Utilisateur>::Gestionnaire()
{
    /*
    utilisateurs.insert("louis", new Client("louis", "Lesniak", "Louis"));
    utilisateurs.insert("theo", new Client("theo", "Joffroy", "Théo"));
    utilisateurs.insert("aboubacar", new Client("aboubacar", "Hassane Chekou Kore", "Aboubacar"));
    utilisateurs.insert("alexis", new Technicien("alexis", "Scheuer", "Alexis"));
    */
}

Utilisateur& Gestionnaire<Utilisateur>::getItem(QString login){

    return *(utilisateurs.value(login));
}

void Gestionnaire<Utilisateur>::ajouterItem(Utilisateur& u){

    if(!utilisateurs.contains(u.getLogin()))
        utilisateurs.insert(u.getLogin(), &u);
}

Gestionnaire<Utilisateur>::~Gestionnaire(){

    qDeleteAll(utilisateurs);
    utilisateurs.clear();
}
