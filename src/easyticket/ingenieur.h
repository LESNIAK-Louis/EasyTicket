#ifndef INGENIEUR_H
#define INGENIEUR_H

#include <QObject>
#include "employe.h"

class Ingenieur :  public Employe
{
    Q_OBJECT
public:
    explicit Ingenieur(QObject *parent = nullptr);


    Ingenieur(std::string login, std::string nom, std::string prenom); 
    bool estUnIngenieur()const;
    ~Ingenieur();
signals:

};

#endif // INGENIEUR_H
