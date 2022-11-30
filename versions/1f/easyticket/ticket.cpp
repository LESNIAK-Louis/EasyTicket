#include "ticket.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"

Ticket::Ticket(QString mtitre, QString mcategorie){
    titre = mtitre;
    categorie = mcategorie;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdTicket();
    dateCreation = getDateEtHeureActuelle();
    dateDerniereModification = dateCreation;
    statut = OUVERT;

    gm = new GestionnaireMessages();
}

Ticket::Ticket(QString mtitre, QString mcategorie, QString mlogiciel){
    titre = mtitre;
    categorie = mcategorie;
    logiciel =  mcategorie;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdTicket();
    dateCreation = getDateEtHeureActuelle();
    dateDerniereModification = dateCreation;
    statut = OUVERT;

    gm = new GestionnaireMessages();
}

void Ticket::ajouterMessage(QString msg, QString redacteur){

    gm->ajouterMessage(new Message(msg, redacteur));
}


Ticket::~Ticket(){

    delete gm;
}
