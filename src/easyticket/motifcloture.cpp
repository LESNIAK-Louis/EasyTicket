#include "motifcloture.h"
#include "ui_motifcloture.h"

motifCloture::motifCloture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::motifCloture)
{
    ui->setupUi(this);
}


void CreationTicket::on_comboBoxStatut_accepted()
{
    GestionnaireDialogue* gd = ((MainWindow*)(this->parent()))->getGD();
    gd->cloturerTicket(ui-> ,ui->champMessage->toPlainText());
    ((MainWindow*)(this->parent()))->mettreAJourEcranPrincipal();

}

motifCloture::~motifCloture()
{
    delete ui;
}
