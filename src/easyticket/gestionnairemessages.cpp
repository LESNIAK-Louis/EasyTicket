#include "gestionnairemessages.h"

GestionnaireMessages::GestionnaireMessages(){

}

Message* GestionnaireMessages::getMessage(int id){
    return messages.value(id);
}

QMap<int,Message*> GestionnaireMessages::getMessages(){
    return messages;
}
void GestionnaireMessages::ajouterMessage(Message* mes){
    messages.insert(mes->getId(), mes);
}

GestionnaireMessages::~GestionnaireMessages(){

}
