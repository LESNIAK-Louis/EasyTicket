#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // On met la bonne taille à la fenêtre, on empêche le resize et on défini le titre
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("EasyTicket");

    gd = new GestionnaireDialogue();
    login = new Login(this);
}

void MainWindow::deconnexion(){
    gd->nouveauDialogue();
    login->deconnexion();
}

MainWindow::~MainWindow()
{
    delete login;
    delete gd;
    delete ui;
}

