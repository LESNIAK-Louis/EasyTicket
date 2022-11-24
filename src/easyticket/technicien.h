#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "employe.h"

class Technicien : public Employe
{
public:
    Technicien(QString login, QString nom, QString prenom);

    bool estUnTechnicien() const;
    ~Technicien();
};

#endif // TECHNICIEN_H
