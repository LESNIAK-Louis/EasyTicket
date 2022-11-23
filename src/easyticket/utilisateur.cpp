#include "utilisateur.h"

Utilisateur::Utilisateur(QObject *parent) : QObject(parent)
{

}

Utilisateur::Utilisateur(std::m_login,std::m_nom,std::m_prenom){
login = m_login;
nom = m_nom;
prenom = m_prenom;
}
