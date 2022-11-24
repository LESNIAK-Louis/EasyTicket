#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "utilisateur.h"

class Employe : public Utilisateur
{
public:
    Employe(QString login, QString nom, QString prenom);
    bool estUnEmploye() const;
    ~Employe();

signals:

};

#endif // EMPLOYE_H
