#include "gestionnairetickets.h"
#include "client.h"

#include <QDebug>

using namespace std;

GestionnaireTickets::GestionnaireTickets(){
}

QMap<int,Ticket*> GestionnaireTickets::getTickets(){
   return tickets;
}

Ticket* GestionnaireTickets::getTicket(int id){
   return tickets.value(id);
}
Ticket* GestionnaireTickets::ajouterTicket(QString titre, QString categorie, QString logiciel, QString message, Client* redacteur){

    Ticket* t = new Ticket(titre, categorie, logiciel, redacteur);
    t->ajouterMessage(message, QString(redacteur->getPrenom() + " " + redacteur->getNom()));

    tickets.insert(t->getId(), t);

    return t;
}

void GestionnaireTickets::ajouterTicket(Ticket* ticket){
    tickets.insert(ticket->getId(), ticket);
}

GestionnaireTickets::~GestionnaireTickets()
{
    qDeleteAll(tickets);
    tickets.clear();
}
