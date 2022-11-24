#include "utilisateur.h"

Utilisateur::Utilisateur(QString m_login, QString m_nom, QString m_prenom){
    this->login = m_login;
    this->nom = m_nom;
    this->prenom = m_prenom;
}

Utilisateur::~Utilisateur()
{
}
