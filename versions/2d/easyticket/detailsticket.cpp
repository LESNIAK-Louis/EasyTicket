#include "detailsticket.h"
#include "ui_detailsticket.h"
#include "mainwindow.h"
#include "motifcloture.h"
#include "dialogcombobox.h"
#include "ecranprincipal.h"

#include <QScrollBar>

DetailsTicket::DetailsTicket(QWidget *parent, Ticket* ticket) :
    QDialog(parent),
    ui(new Ui::DetailsTicket)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Détails du ticket");

    ui->scrollAreaWidgetContents->setLayout(ui->zoneMessagesLayout);
    this->ticket = ticket;
    chargerMessages();
}

void DetailsTicket::chargerMessages(){
    ui->labelTitre->setText(ticket->getTitre());
    ui->labelID->setText("ID\n" + QString::number(ticket->getId()));
    ui->labelStatut->setText("Statut\n" + ticket->getStatutString());
    ui->labelDate->setText("Créé le\n" + ticket->getDateCreation());
    ui->labelCategorie->setText("Catégorie\n" + ticket->getCategorie());
    ui->labelLogiciel->setText("Logiciel\n" + ticket->getLogiciel());

    if(((EcranPrincipal*)this->parent())->getUtilisateur()->estUnEmploye())
    {
        ui->boutonModifierCateg->setVisible(true);
    }
    else{
        ui->boutonModifierCateg->setVisible(false);
    }

    if(ticket->getStatut() != OUVERT){
        ui->boutonCloturer->setEnabled(false);
        ui->inputReponse->setEnabled(false);
        ui->boutonEnvoyer->setEnabled(false);
    }

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

void DetailsTicket::on_boutonModifierCateg_clicked()
{
    DialogComboBox* dialog = new DialogComboBox(this);
    dialog->addItem("Bug");
    dialog->addItem("Question");
    dialog->addItem("Réclamation");
    dialog->setTitle("Choisissez une catégorie");
    dialog->setMessage("Choisissez une catégorie à affecter au ticket");
    dialog->exec();

    ticket->setCategorie(dialog->getStringResult());
    delete dialog;

    ui->labelCategorie->setText("Catégorie\n" + ticket->getCategorie());
    ((EcranPrincipal*)this->parent())->chargerTickets();
}

void DetailsTicket::on_boutonEnvoyer_clicked()
{
    GestionnaireDialogue* gd = ((MainWindow*)(this->parent()->parent()))->getGD();

    if(ui->inputReponse->toPlainText() != ""){
        ticket->ajouterMessage(ui->inputReponse->toPlainText(),
                               gd->getUtilisateur()->getPrenom() + " " +
                               gd->getUtilisateur()->getNom());

        chargerMessages();
        ui->inputReponse->clear();
    }
}

void DetailsTicket::on_boutonCloturer_clicked(){
    MotifCloture* motifCloture = new MotifCloture(this, this->ticket);
    motifCloture->exec();
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


