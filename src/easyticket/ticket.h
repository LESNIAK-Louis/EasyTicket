#ifndef TICKET_H
#define TICKET_H

#include <QString>

class Ticket
{
public:
    Ticket(QString titre, QString categorie);
    Ticket(QString titre, QString categorie,  QString logiciel);
    void ajouterMessage(QString msg);
     ~Ticket();
private:
    QString  id;
    QString titre;
    QString categorie;
    QString logiciel;
    QString dateCreation;
    QString datePriseEnCharge;
    QString dateCloture;
};

#endif // TICKET_H
