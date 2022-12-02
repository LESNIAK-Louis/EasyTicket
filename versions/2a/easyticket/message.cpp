#include "message.h"
#include "fabriqueidentifiant.h"
#include "utilitaires.h"

Message::Message(QString contenu, QString redacteur)
{
    this->contenu = contenu;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdMessage();

    this->redacteur = redacteur;
    this->dateMessage = getDateEtHeureActuelle();
}

Message::~Message(){

}
