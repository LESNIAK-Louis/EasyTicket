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
    // On met la bonne taille à la fenêtre et on empêche le resize
    ((MainWindow*)(this->parent()))->setFixedSize(this->width(),this->height());
    setWindowFlags(this->windowFlags()| Qt::MSWindowsFixedSizeDialogHint);
}

QString const Login::getLogin(){ return this->ui->champLogin->text(); }

QString const Login::getPassword(){ return this->ui->champMdp->text(); }

void Login::deconnexion(){
    delete ecranPrincipal;
    // on resize la fenêtre à la taille de login
    ((MainWindow*)(this->parent()))->setFixedSize(this->width(),this->height());
    this->show();
}

Login::~Login()
{
    delete ui;
}

void Login::on_boutonLogin_clicked()
{
    // on essaye de retrouver l'utilisateur dans la base de données
    GestionnaireDialogue& gd = ((MainWindow*)(this->parent()))->getGD();
    bool b = gd.tentativeConnexion(getLogin(), getPassword());
    if(b){ // trouvé
        // Affichage de l'écran principal relatif à l'utilisateur
        ecranPrincipal = new EcranPrincipal((MainWindow*)this->parent());
        ecranPrincipal->show();
        ecranPrincipal->chargerTickets();
        this->hide();
        ui->champLogin->setText("");
        ui->champMdp->setText("");
        ui->labelErreur->setText("");
    }else{ // non trouvé
        ui->labelErreur->setText("Erreur : utilisateur inconnu");
        ui->labelErreur->setStyleSheet("QLabel { color : red; }");
    }
}
