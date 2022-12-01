#include "creationticket.h"
#include "ui_creationticket.h"
#include "ecranprincipal.h"
#include "mainwindow.h"

CreationTicket::CreationTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationTicket)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());

    ui->comboBoxCategorie->addItem("Bug");
    ui->comboBoxCategorie->addItem("Question");
    ui->comboBoxCategorie->addItem("Réclamation");

    ui->comboBoxLogiciel->addItem("Twisk");
    ui->comboBoxLogiciel->addItem("Easy Tickets");
    ui->comboBoxLogiciel->addItem("Easy Drinks");

}

CreationTicket::~CreationTicket()
{
    delete ui;
}

void CreationTicket::on_comboBoxResultat_accepted()
{
    GestionnaireDialogue* gd = ((MainWindow*)(this->parent()->parent()))->getGD();
    gd->creerTicket(ui->champTitre->text(), ui->comboBoxCategorie->currentText(),
                    ui->comboBoxLogiciel->currentText(), ui->champMessage->toPlainText());
    ((EcranPrincipal*)(this->parent()))->chargerTickets();

}
