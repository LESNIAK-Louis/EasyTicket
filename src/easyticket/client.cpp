#include "client.h"
#include "utilisateur.h"

Client::Client(QString login, QString nom, QString prenom):Utilisateur(login,nom,prenom){
}

void Client::creerTicket(QString titre, QString categorie, QString message){

    creerTicket(titre, categorie, "", message);
}

void Client::creerTicket(QString titre, QString categorie, QString logiciel, QString message){

    gestionnaireTickets->ajouterTicket(titre, categorie, logiciel, message);
}


Client::~Client()
{
}
