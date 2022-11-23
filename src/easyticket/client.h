#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "utilisateur.h"

class Client : public Utilisateur
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    Client(std::string login, std::string nom, std::string prenom);
    bool estUnClient();
    void creerTicket(std::string titre, std::string categorie, std::string message);
    void creerTicket(std::string titre, std::string categorie, std::string logiciel, std::string message);
 ~Client();
signals:

};

#endif // CLIENT_H
