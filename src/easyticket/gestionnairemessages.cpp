#include "gestionnairemessages.h"

GestionnaireMessages::GestionnaireMessages(){

}

Message* GestionnaireMessages::getMessage(int id){
    return messages.value(id);
}

QMap<int,Message*> GestionnaireMessages::getMessages(){
    return messages;
}
void GestionnaireMessages::ajouterMessage(Message* msg){
    messages.insert(msg->getId(), msg);
}

GestionnaireMessages::~GestionnaireMessages(){

    foreach(Message* m, messages.values()){
        delete m;
    }
}
