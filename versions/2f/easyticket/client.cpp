#include "client.h"
#include "utilisateur.h"

Client::Client(QString login, QString nom, QString prenom):Utilisateur(login,nom,prenom){
}

Ticket* Client::creerTicket(QString titre, QString categorie, QString message){

    return creerTicket(titre, categorie, "", message);
}

Ticket* Client::creerTicket(QString titre, QString categorie, QString logiciel, QString message){

    return gestionnaireTickets->ajouterTicket(titre, categorie, logiciel, message, this);
}


Client::~Client()
{
}
