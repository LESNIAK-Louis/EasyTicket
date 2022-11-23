#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login = new Login(this);

}

MainWindow::~MainWindow()
{
    delete login;
    delete ui;
}

