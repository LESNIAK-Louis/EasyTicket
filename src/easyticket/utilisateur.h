#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QObject>
#include "gestionnairetickets.h"

 class Utilisateur : public QObject
{
    Q_OBJECT
public:
    explicit Utilisateur(QObject *parent = nullptr);

    Utilisateur(std::string login, std::string nom, std::string prenom);
    virtual bool estUnClient() const = 0;
    virtual bool estUnEmploye() const = 0;
    virtual bool estUnIngenieur() const = 0;
    virtual ~Utilisateur();

private:
    std::string login;
    std::string nom;
    std::string prenom;
    GestionnaireTickets gt1;

signals:

};

#endif // UTILISATEUR_H
