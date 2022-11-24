#include "gestionnaireutilisateurs.h"

GestionnaireUtilisateurs::GestionnaireUtilisateurs()
{

    utilisateurs.insert("louis", new Client("louis", "Lesniak", "Louis"));
    utilisateurs.insert("theo", new Client("theo", "Joffroy", "Théo"));
    utilisateurs.insert("aboubacar", new Client("aboubacar", "Hassane Chekou Kore", "Aboubacar"));

}

Utilisateur* GestionnaireUtilisateurs::getUtilisateur(QString login){

    return utilisateurs.value(login);
}
