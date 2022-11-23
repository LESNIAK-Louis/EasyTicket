#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QObject>

 class Utilisateur : public QObject
{
    Q_OBJECT
public:
    explicit Utilisateur(QObject *parent = nullptr);

    Utilisateur(std::string login, std::string nom, std::string prenom);
    virtual void estUnClient() const = 0;
    virtual void estUnEmploye() const = 0;
    virtual void estUnIngenieur() const = 0;
    virtual ~Utilisateur();

private:
    std::string login;
    std::string nom;
    std::string prenom;
    //GestionnaireTickets gt;

signals:

};

#endif // UTILISATEUR_H
