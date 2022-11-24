#include "ticket.h"

Ticket::Ticket(QString mtitre, QString mcategorie){
    titre = mtitre;
    categorie = mcategorie;
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
