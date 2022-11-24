#ifndef TICKET_H
#define TICKET_H

#include <QObject>

class Ticket : public QObject
{
    Q_OBJECT
public:
    explicit Ticket(QObject *parent = nullptr);

    Ticket(std::string titre, std::string categorie);
    Ticket(std::string titre, std::string categorie,  std::string logiciel);
    void ajouterMessage(std::string msg);
     ~Ticket();
private:

    std::string  id;
    std::string titre;
    std::string categorie;
    std::string logiciel;
    std::string dateCreation;
    std::string datePriseEnCharge;
    std::string dateCloture;



signals:

};

#endif // TICKET_H
