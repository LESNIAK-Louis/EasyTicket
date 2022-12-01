#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gd = new GestionnaireDialogue();
    login = new Login(this);
}

MainWindow::~MainWindow()
{
    delete gd;
    delete login;
    delete ui;
}

