#include "detailsticket.h"
#include "ui_detailsticket.h"

DetailsTicket::DetailsTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsTicket)
{
    ui->setupUi(this);
}

void DetailsTicket::chargerMessages(Ticket* ticket){

    ui->labelTitre->setText(ticket->getTitre());

    QMap<int, Message*> messages = ticket->getMessages();

    // Destruction des anciens messages s'il y en a
    QLayoutItem *child;
    while ((child = ui->zoneMessagesLayout->takeAt(0)) != 0) {
       delete child->widget();
       delete child;
    }

    foreach(Message* m, messages.values()){

        MessageInfosTicket* msg = new MessageInfosTicket(nullptr, m);
        ui->zoneMessagesLayout->addWidget(msg);
    }
}

DetailsTicket::~DetailsTicket()
{
    QLayoutItem *child;
    while ((child = ui->zoneMessagesLayout->takeAt(0)) != 0) {
       delete child->widget();
       delete child;
    }
    delete ui;
}
