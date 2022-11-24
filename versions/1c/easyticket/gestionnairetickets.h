#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QObject>
#include <map>
#include "ticket.h"

class GestionnaireTickets
{
public:
    GestionnaireTickets();

    std::map<int,Ticket*> getTickets();
    Ticket* getTicket(int id);
    void ajouterTicket(Ticket* t);

    ~GestionnaireTickets();

private:
    std::map<int ,Ticket*> gestionnaireTickets;
};

#endif // GESTIONNAIRETICKETS_H
