#include "detailsticket.h"
#include "ui_detailsticket.h"
#include "mainwindow.h"

#include <QScrollBar>

DetailsTicket::DetailsTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsTicket)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->setLayout(ui->zoneMessagesLayout);
}

void DetailsTicket::chargerMessages(Ticket* ticket){

    this->ticket = ticket;

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

    ui->zoneMessages->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(ui->zoneMessagesLayout);
    foreach(Message* m, messages.values()){

        MessageInfosTicket* msg = new MessageInfosTicket(nullptr, m);
        ui->zoneMessagesLayout->addWidget(msg);
        ui->zoneMessages->verticalScrollBar()->setValue(
                            ui->zoneMessages->verticalScrollBar()->maximum());
    }
}

void DetailsTicket::on_boutonEnvoyer_clicked()
{
    GestionnaireDialogue* gd = ((MainWindow*)(this->parent()))->getGD();

    if(ui->inputReponse->toPlainText() != ""){
        ticket->ajouterMessage(ui->inputReponse->toPlainText(),
                               gd->getUtilisateur()->getPrenom() + " " +
                               gd->getUtilisateur()->getNom());

        chargerMessages(this->ticket);
        ui->inputReponse->clear();
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


