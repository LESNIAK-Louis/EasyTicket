#include "message.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"
#include "ticket.h"

Message::Message(QString contenu, QString redacteur, Ticket* ticket)
{
    this->contenu = contenu;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdMessage();

    this->redacteur = redacteur;
    this->dateMessage = getDateEtHeureActuelle();
    this->ticket = ticket;
}

Message::Message(int id, QString contenu, QString date, QString redacteur)
{
    this->id = id;
    this->contenu = contenu;
    this->dateMessage = date;
    this->redacteur = redacteur;
}

Message::~Message(){

}
