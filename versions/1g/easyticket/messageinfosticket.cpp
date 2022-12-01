#include "messageinfosticket.h"
#include "ui_messageinfosticket.h"

MessageInfosTicket::MessageInfosTicket(QWidget *parent, Message* m) :
    QWidget(parent),
    ui(new Ui::MessageInfosTicket)
{
    ui->setupUi(this);

    ui->labelUtilisateur->setText(m->getRedacteur());
    ui->labelDateMessage->setText(m->getDateMessage());
    ui->labelContenuMessage->setText(m->getContenu());

}

MessageInfosTicket::~MessageInfosTicket()
{
    delete ui;
}
