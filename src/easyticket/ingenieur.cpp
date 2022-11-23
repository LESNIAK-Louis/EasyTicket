#include "ingenieur.h"

Ingenieur::Ingenieur(QObject *parent) : QObject(parent)
{
    public:
    Ingenieur(std::String login, String nom, String prenom);

    bool Ingenieur::estUnIngenieur() const{
        return true;
    }
}
