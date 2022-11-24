#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "employe.h"

class Ingenieur :  public Employe
{
public:
    Ingenieur(QString login, QString nom, QString prenom);
    bool estUnIngenieur() const;
    ~Ingenieur();
};

#endif // INGENIEUR_H
