#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include "gestionnairemessages.h"

enum statutTicket {
    OUVERT = 1,
    RESOLU = 2,
    INSOLUBLE = 3
};

class Ticket
{
private:
    int  id;
    QString titre;
    QString categorie;
    QString logiciel;
    QString dateCreation;
    QString datePriseEnCharge;
    QString dateCloture;

public:
    Ticket(QString titre, QString categorie);
    Ticket(QString titre, QString categorie,  QString logiciel);


    inline int getId() const { return id; }
    inline QString getTitre() const { return titre; }
    inline QString getCategorie() const { return categorie; }
    inline QString getLogiciel() const { return logiciel; }
    inline QString getDateCreation() const { return dateCreation; }
    inline QString getDatePriseEnCharge() const { return datePriseEnCharge; }
    inline QString getDateCloture() const { return dateCloture; }

    inline void setId(int id) { this->id = id; }
    inline void setTitre(QString titre) { this->titre = titre; }
    inline void setCategorie(QString categorie) { this->categorie = categorie; }
    inline void setLogiciel(QString logiciel) { this->logiciel = logiciel; }
    inline void setDateCreation(QString dateCreation) { this->dateCreation = dateCreation; }
    inline void setDatePriseEnCharge(QString datePriseEnCharge) { this->datePriseEnCharge = datePriseEnCharge; }
    inline void setDateCloture(QString dateCloture) { this->dateCloture = dateCloture; }

    void ajouterMessage(QString msg);

     ~Ticket();

};

#endif // TICKET_H
