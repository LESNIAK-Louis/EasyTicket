#include "gestionnairetickets.h"
#include "client.h"

using namespace std;

GestionnaireTickets::GestionnaireTickets(){
}

QMap<int,Ticket*> GestionnaireTickets::getTickets(){
   return tickets;
}

Ticket* GestionnaireTickets::getTicket(int id){
   return tickets.value(id);
}
void GestionnaireTickets::ajouterTicket(QString titre, QString categorie, QString logiciel, QString message, Client* redacteur){

    Ticket* t = new Ticket(titre, categorie, logiciel, redacteur);
    t->ajouterMessage(message, QString(redacteur->getPrenom() + " " + redacteur->getNom()));

    tickets.insert(t->getId(), t);
}

GestionnaireTickets::~GestionnaireTickets()
{
    foreach(Ticket* t, tickets.values()){
        delete t;
    }
}
