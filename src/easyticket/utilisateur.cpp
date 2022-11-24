#include "utilisateur.h"

Utilisateur::Utilisateur(QObject *parent) : QObject(parent)
{

}

Utilisateur::Utilisateur(std::string m_login,std::string m_nom,std::string m_prenom){
login = m_login;
nom = m_nom;
prenom = m_prenom;
}

Utilisateur::~Utilisateur()
{
}
