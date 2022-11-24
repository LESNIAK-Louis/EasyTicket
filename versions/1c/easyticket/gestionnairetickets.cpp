#include "gestionnairetickets.h"
#include <map>

using namespace std;

GestionnaireTickets::GestionnaireTickets(){
}



map<int,Ticket*> GestionnaireTickets::getTickets(){

    return gestionnaireTickets;
}

Ticket* GestionnaireTickets::getTicket(int id){
    return NULL;
}

void GestionnaireTickets::ajouterTicket(Ticket* t){
}

GestionnaireTickets::~GestionnaireTickets()
{
}
