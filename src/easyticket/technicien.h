#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <QObject>
#include "employe.h"

class Technicien : public Employe
{
    Q_OBJECT
public:
    explicit Technicien(QObject *parent = nullptr);

    Technicien(std::string login, std::string nom, std::string prenom);

    bool estUnTechnicien()const;
    ~Technicien();
signals:

};

#endif // TECHNICIEN_H
