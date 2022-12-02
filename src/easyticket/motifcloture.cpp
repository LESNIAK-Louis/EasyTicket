#include "motifcloture.h"
#include "ui_motifcloture.h"
#include "ecranprincipal.h"
#include "detailsticket.h"
#include "mainwindow.h"

MotifCloture::MotifCloture(QWidget *parent, Ticket* ticket) :
    QDialog(parent),
    ui(new Ui::MotifCloture)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Clôture du ticket");

    this->ticket = ticket;
    ui->comboBoxStatut->addItem("RESOLU");
    ui->comboBoxStatut->addItem("INSOLUBLE");

}

MotifCloture::~MotifCloture()
{
    delete ui;
}

void MotifCloture::on_comboBoxResultat_accepted()
{
    DetailsTicket* detailTicket = (DetailsTicket*)this->parent();
    EcranPrincipal* ecranPrincipal = (EcranPrincipal*)(detailTicket->parent());
    MainWindow* mainWindow = (MainWindow*)ecranPrincipal->parent();

    GestionnaireDialogue* gd = mainWindow->getGD();
    gd->cloturerTicket(ticket, ui->comboBoxStatut->currentText() , ui->champMessage->toPlainText());
    ecranPrincipal->chargerTickets();
    detailTicket->chargerMessages();

}
