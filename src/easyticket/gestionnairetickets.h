#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QMap>
#include "ticket.h"

class GestionnaireTickets
{
private:
    QMap<int,Ticket*> tickets;

public:
    GestionnaireTickets();

    Ticket* getTicket(int id);

    void ajouterTicket(Ticket* t);

    ~GestionnaireTickets();

};

#endif // GESTIONNAIRETICKETS_H
