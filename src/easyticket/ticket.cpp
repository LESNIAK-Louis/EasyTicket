#include "ticket.h"

Ticket::Ticket(QObject *parent) : QObject(parent)
{

}

Ticket::Ticket(std::string mtitre, std::string mcategorie){
    titre = mtitre;
    categorie = mcategorie;
}

Ticket::Ticket(std::string mtitre, std::string mcategorie, std::string mlogiciel){
    titre = mtitre;
    categorie = mcategorie;
    logiciel =  mcategorie;
}

void Ticket::ajouterMessage(std::string msg){

}


Ticket::~Ticket(){

}
