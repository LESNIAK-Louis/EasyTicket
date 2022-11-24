#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login = new Login(this);
}

QString MainWindow::getNom(){
    return this->nom;
}

void MainWindow::setNom(QString nom){
    this->nom = nom;
}

void MainWindow::AfficherEcranPrincipal(){

    delete login;
    ecranPrincipal = new EcranPrincipal(this);
    ecranPrincipal->show();
}

MainWindow::~MainWindow()
{
    delete login;
    delete ecranPrincipal;
    delete ui;
}

