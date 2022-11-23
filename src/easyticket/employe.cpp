#include "employe.h"

Employe::Employe(QObject *parent) : Utilisateur(parent)
{


}

Employe::Employe(std::string m_login, std::string m_nom, std::string m_prenom):Utilisateur(m_login,m_nom,m_prenom){

}


bool Employe::estUnEmploye() const{
   return true;
}
