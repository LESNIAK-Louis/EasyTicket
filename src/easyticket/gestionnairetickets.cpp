#include "gestionnairetickets.h"
#include <map>

using namespace std;

GestionnaireTickets::GestionnaireTickets(QObject *parent) : QObject(parent)
{

}

GestionnaireTickets::GestionnaireTickets(){
}



map<int,Ticket*> GestionnaireTickets::getTickets(){

    return gt1;
}

Ticket* GestionnaireTickets::getTicket(int id){

    map<int ,Ticket*>::iterator it;
     it = gt1.find(id);

     if(it == gt1.end()){
         //Ticket non trouvé
         return NULL;
     }
     else{
         return (*it)->value;
     }

}

void GestionnaireTickets::ajouterTicket(Ticket* t){
    gt1.push_back(t);
}

GestionnaireTickets::~GestionnaireTickets()
{
}
