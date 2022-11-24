#include "client.h"
#include "utilisateur.h"

Client::Client(QObject *parent) : Utilisateur(parent)
{

}

Client::Client(std::string login, std::string nom, std::string prenom):Utilisateur(login,nom,prenom){

}

bool Client::estUnClient(){
    return true;
}
//clieent doit connaitre ticket ?
void Client::creerTicket(std::string titre, std::string categorie, std::string message){
//Ticket t1 = new Ticket (...);
//getionnaireTicket.ajouter(t1);

}


Client::~Client()
{
}
