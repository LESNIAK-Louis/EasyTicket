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
    ui->labelID->setText("ID\n" + QString::number(ticket->getId()));
    ui->labelStatut->setText("Statut\n" + ticket->getStatut());
    ui->labelDate->setText("Créé le\n" + ticket->getDateCreation());
    ui->labelCategorie->setText("Catégorie\n" + ticket->getCategorie());
    ui->labelLogiciel->setText("Logiciel\n" + ticket->getLogiciel());

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

void EcranPrincipal::on_pushButtonBoutonCloturer_clicked(){
    MainWindow* mainWindow = (MainWindow*)(this->parent());
    mainWindow->afficherMotifCloture();
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
