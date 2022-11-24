#include "client.h"
#include "utilisateur.h"

Client::Client(QString login, QString nom, QString prenom):Utilisateur(login,nom,prenom){
}

bool Client::estUnClient(){
    return true;
}
//clieent doit connaitre ticket ?
void Client::creerTicket(QString titre, QString categorie, QString message){
//Ticket t1 = new Ticket (...);
//getionnaireTicket.ajouter(t1);

}


Client::~Client()
{
}
