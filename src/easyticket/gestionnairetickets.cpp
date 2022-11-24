#include "gestionnairetickets.h"

using namespace std;

GestionnaireTickets::GestionnaireTickets(){
}

QMap<int,Ticket*> GestionnaireTickets::getTickets(){
   return tickets;
}

Ticket* GestionnaireTickets::getTicket(int id){
   return tickets.value(id);
}
void GestionnaireTickets::ajouterTicket(QString titre, QString categorie, QString logiciel, QString message){

    Ticket* t = new Ticket(titre, categorie, logiciel);
    t->ajouterMessage(message);

    tickets.insert(t->getId(), t);
}

GestionnaireTickets::~GestionnaireTickets()
{
}
