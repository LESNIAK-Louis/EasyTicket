#include "ecranprincipal.h"
#include "ui_ecranprincipal.h"
#include "mainwindow.h"
#include <QMessageBox>

EcranPrincipal::EcranPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EcranPrincipal)
{
    ui->setupUi(this);
    ui->labelNom->setText("Bienvenue : "+((MainWindow*)(this->parent()))->getNom());
}

EcranPrincipal::~EcranPrincipal()
{
    delete ui;
}
