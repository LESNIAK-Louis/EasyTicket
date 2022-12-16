#include "gestionnairemessages.h"

Gestionnaire<Message>::Gestionnaire(){

}

Message& Gestionnaire<Message>::getItem(int id){
    return *(messages.value(id));
}

QMap<int,Message*> Gestionnaire<Message>::getCollection(){
    return messages;
}

void Gestionnaire<Message>::ajouterItem(Message& msg){
    messages.insert(msg.getId(), &msg);
}

Gestionnaire<Message>::~Gestionnaire(){

    qDeleteAll(messages);
    messages.clear();
}
