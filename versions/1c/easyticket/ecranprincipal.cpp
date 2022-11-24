#include "ecranprincipal.h"
#include "ui_ecranprincipal.h"
#include "mainwindow.h"

#include <QMessageBox>

EcranPrincipal::EcranPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EcranPrincipal)
{
    ui->setupUi(this);
    Utilisateur* u = ((MainWindow*)(this->parent()))->getGD()->getUtilisateur();
    ui->labelNom->setText("Bienvenue " + u->getPrenom() + " " + u->getNom());
}

void EcranPrincipal::on_pushButtonCreationTicket_clicked(){
    MainWindow* mainWindow = (MainWindow*)(this->parent());
    mainWindow->afficherCreationTicket();
}


EcranPrincipal::~EcranPrincipal(){
    delete ui;
}
