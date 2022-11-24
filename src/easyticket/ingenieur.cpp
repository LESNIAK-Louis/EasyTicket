#include "ingenieur.h"

Ingenieur::Ingenieur(QString login, QString nom, QString prenom):Employe(login,nom,prenom){}

bool Ingenieur::estUnIngenieur() const{
    return true;
}

Ingenieur::~Ingenieur()
{
}
