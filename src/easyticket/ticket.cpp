#include "ticket.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"
#include "client.h"
#include "employe.h"

#include <QDebug>

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

Ticket::Ticket(int id, QString titre, QString categorie,  QString logiciel, QString dateCreation,
               QString datePriseEnCharge, QString dateDerniereModification, QString dateCloture,
               int statut, Client* client, Employe* employe){
    this->id = id;
    this->titre = titre;
    this->categorie = categorie;
    this->logiciel =  logiciel;
    this->dateCreation = dateCreation;
    this->datePriseEnCharge = datePriseEnCharge;
    this->dateDerniereModification = dateDerniereModification;
    this->dateCloture = dateCloture;
    this->statut = (statutTicket)statut;
    this->client = client;
    this->employe = employe;

    gm = new GestionnaireMessages();
}

Message& Ticket::ajouterMessage(QString msg, QString redacteur){

    Message& m = *(new Message(msg, redacteur, this));
    gm->ajouterMessage(m);

    return m;
}

Message& Ticket::cloturerTicket(statutTicket statut, QString msg, QString redacteur){
    setStatut(statut);
    setDateDerniereModification(getDateEtHeureActuelle());
    setDateCloture(getDateEtHeureActuelle());
    Message& m = *(new Message(msg, redacteur, this));
    gm->ajouterMessage(m);

    return m;
}

void Ticket::chargerMessages(GestionnaireMessages& messages){

    delete gm;
    gm = &messages;
}

Ticket::~Ticket(){

    delete gm;
}
