#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

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
        ((MainWindow*)(this->parent()))->afficherEcranPrincipal();
    }else{
        ui->labelErreur->setText("Erreur : utilisateur inconnu");
        ui->labelErreur->setStyleSheet("QLabel { color : red; }");
    }
}
