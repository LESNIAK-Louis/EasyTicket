#include "ticket.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"
#include "client.h"
#include "employe.h"

Ticket::Ticket(QString mtitre, QString mcategorie, Client* client){
    titre = mtitre;
    categorie = mcategorie;
    logiciel = QString("Non renseigné");
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdTicket();
    dateCreation = getDateEtHeureActuelle();
    dateDerniereModification = dateCreation;
    statut = OUVERT;
    this->client = client;

    gm = new GestionnaireMessages();
}

Ticket::Ticket(QString mtitre, QString mcategorie, QString mlogiciel, Client* client){

    titre = mtitre;
    categorie = mcategorie;
    logiciel =  mlogiciel;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdTicket();
    dateCreation = getDateEtHeureActuelle();

    dateDerniereModification = dateCreation;
    statut = OUVERT;
    this->client = client;

    gm = new GestionnaireMessages();
}

void Ticket::ajouterMessage(QString msg, QString redacteur){

    gm->ajouterMessage(new Message(msg, redacteur, this));
}

void Ticket::cloturerTicket(statutTicket statut, QString msg, QString redacteur){
    setStatut(statut);
    setDateDerniereModification(getDateEtHeureActuelle());
    setDateCloture(getDateEtHeureActuelle());
    gm->ajouterMessage(new Message(msg, redacteur, this));
}

Ticket::~Ticket(){

    delete gm;
}
