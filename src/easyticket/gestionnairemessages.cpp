#include "gestionnairemessages.h"
#include "QMap"


GestionnaireMessages::GestionnaireMessages(){

}

Message* GestionnaireMessages::getMessage(int id){
    return gm1.value(id);
}

QMap<int,Message*> GestionnaireMessages::getMessages(){
    return gm1;
}
void GestionnaireMessages::ajouterMessage(Message* mes){
    gm1.insert(mes->getID(),mes);
}
