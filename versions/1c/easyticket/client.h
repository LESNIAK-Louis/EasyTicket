#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

class Client : public Utilisateur
{
public:
    Client(QString login, QString nom, QString prenom);
    bool estUnClient();
    void creerTicket(QString titre, QString categorie, QString message);
    //void creerTicket(QString titre, QString categorie, QString logiciel, QString message);
    ~Client();
signals:

};

#endif // CLIENT_H
