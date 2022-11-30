#ifndef DETAILSTICKET_H
#define DETAILSTICKET_H

#include "messageinfosticket.h"
#include "ticket.h"
#include <QDialog>

namespace Ui {
class DetailsTicket;
}

class DetailsTicket : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsTicket(QWidget *parent = nullptr);
    ~DetailsTicket();

    /**
     * @brief Affiche les messages correspondants au ticket
     * @param ticket Ticket
     */
    void chargerMessages(Ticket* ticket);

private:
    Ui::DetailsTicket *ui;
};

#endif // DETAILSTICKET_H
