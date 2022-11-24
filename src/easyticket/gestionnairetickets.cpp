#include "gestionnairetickets.h"
#include <QMap>

using namespace std;

GestionnaireTickets::GestionnaireTickets(QObject *parent) : QObject(parent)
{

}

GestionnaireTickets::GestionnaireTickets(){
}



QMap<int,Ticket*> GestionnaireTickets::getTickets(){

    return gt1;
}

Ticket* GestionnaireTickets::getTicket(int id){
     return gt1.value(id);

}

void GestionnaireTickets::ajouterTicket(Ticket* t){
    gt1.insert(t->getID(),t);
}

GestionnaireTickets::~GestionnaireTickets()
{
}
