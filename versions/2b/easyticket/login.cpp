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
    ((MainWindow*)(this->parent()))->setFixedSize(this->width(),this->height());
    setWindowFlags(this->windowFlags()| Qt::MSWindowsFixedSizeDialogHint);
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
        ecranPrincipal = new EcranPrincipal((MainWindow*)this->parent());
        ecranPrincipal->show();
        ecranPrincipal->chargerTickets();
        delete this;
    }else{
        ui->labelErreur->setText("Erreur : utilisateur inconnu");
        ui->labelErreur->setStyleSheet("QLabel { color : red; }");
    }
}
