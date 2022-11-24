#include "creationticket.h"
#include "ui_creationticket.h"

CreationTicket::CreationTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationTicket)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

CreationTicket::~CreationTicket()
{
    delete ui;
}
