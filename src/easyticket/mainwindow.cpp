#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gd = new GestionnaireDialogue();
    login = new Login(this);
}

void MainWindow::afficherEcranPrincipal(){

    delete login;
    ecranPrincipal = new EcranPrincipal(this);
    ecranPrincipal->show();
    mettreAJourEcranPrincipal();
}

void MainWindow::mettreAJourEcranPrincipal(){
    ecranPrincipal->chargerTickets(gd->getUtilisateur());
}

void MainWindow::afficherCreationTicket(){
    creationTicket = new CreationTicket(this);
    creationTicket->show();
}


void MainWindow::afficherTicket(Ticket* ticket){

    detailsTicket = new DetailsTicket(this);
    detailsTicket->show();
    detailsTicket->chargerMessages(ticket);

}

void MainWindow::afficherMotifCloture(){

}

MainWindow::~MainWindow()
{
    delete gd;
    delete login;
    delete creationTicket;
    delete detailsTicket;
    delete ecranPrincipal;
    delete ui;
}

