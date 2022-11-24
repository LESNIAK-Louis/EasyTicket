#include "ingenieur.h"

Ingenieur::Ingenieur(QObject *parent) : Employe(parent)
{


}
Ingenieur::Ingenieur(std::string login, std::string nom, std::string prenom):Employe(login,nom,prenom){}


bool Ingenieur::estUnIngenieur() const{
    return true;
}

Ingenieur::~Ingenieur()
{
}
