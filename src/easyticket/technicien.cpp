#include "technicien.h"

Technicien::Technicien(QObject *parent) : QObject(parent)
{

}

Technicien(std::string login, std::string nom, std::string prenom):Personnage(login,nom,prenom){}


Technicien::estUnTechnicien(){
    return true;
}
