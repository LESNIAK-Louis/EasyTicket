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
}

void MainWindow::afficherCreationTicket(){
    creationTicket = new CreationTicket(this);
    creationTicket->show();
}

MainWindow::~MainWindow()
{
    delete login;
    delete ecranPrincipal;
    delete ui;
}

