#include "message.h"
#include "fabriqueidentifiant.h"

Message::Message(QString contenu)
{
    contenu = contenu;
    FabriqueIdentifiant *fi = fi->getInstance();
    id = fi->getIdMessage();
}

Message::~Message(){

}
