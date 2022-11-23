#include "ingenieur.h"

Ingenieur::Ingenieur(QObject *parent) : QObject(parent)
{




}
Ingenieur(std::String login, std::string nom, std::string prenom):Personnage(login,nom,prenom){}


bool Ingenieur::estUnIngenieur() const{
    return true;
}
