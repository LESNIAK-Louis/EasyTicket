#include "employe.h"

Employe::Employe(QString m_login, QString m_nom, QString m_prenom):Utilisateur(m_login,m_nom,m_prenom){

}


bool Employe::estUnEmploye() const{
   return true;
}


Employe::~Employe()
{
}
