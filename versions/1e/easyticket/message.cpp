#include "message.h"
#include "fabriqueidentifiant.h"

Message::Message(QString contenu)
{
    this->contenu = contenu;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdMessage();
}

Message::~Message(){

}
