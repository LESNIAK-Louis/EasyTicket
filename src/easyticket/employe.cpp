#include "employe.h"

Employe::Employe(QObject *parent) : QObject(parent)
{

    //Employe(String login, String nom, String prenom);
     bool Employe::estUnEmploye() const{
        return true;
    }
}
