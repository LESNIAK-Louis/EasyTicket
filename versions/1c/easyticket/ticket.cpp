#include "ticket.h"
#include "fabriqueidentifiant.h"

Ticket::Ticket(QString mtitre, QString mcategorie){
    titre = mtitre;
    categorie = mcategorie;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdMessage();
}

Ticket::Ticket(QString mtitre, QString mcategorie, QString mlogiciel){
    titre = mtitre;
    categorie = mcategorie;
    logiciel =  mcategorie;
}

void Ticket::ajouterMessage(QString msg){

}


Ticket::~Ticket(){

}
