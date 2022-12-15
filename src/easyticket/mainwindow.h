#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ecranprincipal.h"
#include "login.h"
#include "creationticket.h"
#include "detailsticket.h"
#include "fabriqueidentifiant.h"
#include "gestionnairedialogue.h"
#include "motifcloture.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Fenêtre de démarrage de l'interface graphique
 * @authors Théo JOFFROY, Aboubacar HASSANE CHEKOU KORE, Louis LESNIAK
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /**
     * @brief l'UI de la MainWindow
     */
    Ui::MainWindow *ui;
    /**
     * @brief Widget login
     */
    Login *login;
    /**
     * @brief Gestion du dialogue entre l'UI et les données
     */
    GestionnaireDialogue *gd;

public:
    /**
     * @brief Constructeur de la MainWindow
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Constructeur de la MainWindow
     * @return gd Le gestionnaire de dialogue
     */
    inline GestionnaireDialogue& getGD() const { return *gd; }

    /**
     * Déconnecte l'utilisateur en cours et réaffiche la page de login
     */
    void deconnexion();

    /**
     * @brief Destructeur de la MainWindow
     */
    ~MainWindow();
};
#endif // MAINWINDOW_H
