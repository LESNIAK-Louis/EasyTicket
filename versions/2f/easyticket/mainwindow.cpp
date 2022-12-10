#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("EasyTicket");

    gd = new GestionnaireDialogue();
    login = new Login(this);
}

MainWindow::~MainWindow()
{
    delete login;
    delete gd;
    delete ui;
}

