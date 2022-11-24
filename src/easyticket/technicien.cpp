#include "technicien.h"

Technicien::Technicien(QString login, QString nom, QString prenom):Employe(login,nom,prenom){}

bool Technicien::estUnTechnicien() const{
    return true;
}

Technicien::~Technicien()
{
}
