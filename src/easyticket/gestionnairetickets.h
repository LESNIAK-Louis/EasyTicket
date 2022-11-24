#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QObject>
#include <queue>

using namespace std;

class GestionnaireTickets : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireTickets(QObject *parent = nullptr);
    ~GestionnaireTickets();

private:
    //remplacer int par ticket apres la creation de la classe Ticket
    queue<int> file;
signals:

};

#endif // GESTIONNAIRETICKETS_H
