#include "ticket.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"

Ticket::Ticket(QString mtitre, QString mcategorie){
    titre = mtitre;
    categorie = mcategorie;
    logiciel = QString("Non renseigné");
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
    logiciel =  mlogiciel;
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

void Ticket::cloturerTicket(statutTicket statut, QString msg, QString redacteur){
    setStatut(statut);
    setDateDerniereModification(getDateEtHeureActuelle());
    setDateCloture(getDateEtHeureActuelle());
    gm->ajouterMessage(new Message(msg, redacteur));
}

Ticket::~Ticket(){

    delete gm;
}
