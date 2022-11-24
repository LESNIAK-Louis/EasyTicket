#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ecranprincipal.h"
#include "creationticket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString getNom();
    void setNom(QString nom);
    void afficherEcranPrincipal();
    void afficherCreationTicket();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Login *login;
    EcranPrincipal *ecranPrincipal;
    CreationTicket *creationTicket;
    QString nom;

};
#endif // MAINWINDOW_H
