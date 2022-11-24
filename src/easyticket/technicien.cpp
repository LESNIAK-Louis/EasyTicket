#include "technicien.h"

Technicien::Technicien(QObject *parent) : Employe(parent)
{

}

Technicien::Technicien(std::string login, std::string nom, std::string prenom):Employe(login,nom,prenom){}


bool Technicien::estUnTechnicien() const{
    return true;
}

Technicien::~Technicien()
{
}
