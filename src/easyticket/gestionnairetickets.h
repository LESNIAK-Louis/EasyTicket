#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QObject>
#include <map>
#include "ticket.h"

using namespace std;

class GestionnaireTickets : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireTickets(QObject *parent = nullptr);
    GestionnaireTickets();
    map<int,Ticket*> getTickets();
    Ticket* getTicket(int id);
    void ajouterTicket(Ticket* t);

    ~GestionnaireTickets();

private:
    map<int ,Ticket*> gt1;

signals:

};

#endif // GESTIONNAIRETICKETS_H
