#include "gestionnairetickets.h"

using namespace std;

GestionnaireTickets::GestionnaireTickets(){
}


Ticket* GestionnaireTickets::getTicket(int id){
   return tickets.value(id);
}

void GestionnaireTickets::ajouterTicket(Ticket* t){
    tickets.insert(t->getId(), t);
}

GestionnaireTickets::~GestionnaireTickets()
{
}
