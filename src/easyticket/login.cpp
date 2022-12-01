#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ecranprincipal.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_boutonLogin_clicked()
{
    GestionnaireDialogue* gd = ((MainWindow*)(this->parent()))->getGD();
    bool b = gd->tentativeConnexion(ui->champLogin->text());
    if(b){
        EcranPrincipal* ecranPrincipal = new EcranPrincipal((MainWindow*)this->parent());
        ecranPrincipal->show();
        ecranPrincipal->chargerTickets();
    }else{
        ui->labelErreur->setText("Erreur : utilisateur inconnu");
        ui->labelErreur->setStyleSheet("QLabel { color : red; }");
        qDebug("sdsf");
    }
}
