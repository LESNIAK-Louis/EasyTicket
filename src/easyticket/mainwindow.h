#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ecranprincipal.h"
#include "login.h"
#include "creationticket.h"
#include "fabriqueidentifiant.h"
#include "gestionnairedialogue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    GestionnaireDialogue* getGD() const { return gd; }
    void afficherEcranPrincipal();
    void afficherCreationTicket();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Login *login;
    EcranPrincipal *ecranPrincipal;
    CreationTicket *creationTicket;
    GestionnaireDialogue *gd;

};
#endif // MAINWINDOW_H
