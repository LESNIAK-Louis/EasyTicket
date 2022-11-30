#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ecranprincipal.h"
#include "login.h"
#include "creationticket.h"
#include "detailsticket.h"
#include "fabriqueidentifiant.h"
#include "gestionnairedialogue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Fenêtre de démarrage de l'interface graphique
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
     * @brief Ecran Principal des commandes
     */
    EcranPrincipal *ecranPrincipal;
    /**
     * @brief Dialog à remplir lors de la création d'un ticket
     */
    CreationTicket *creationTicket;
    /**
     * @brief Dialog à remplir lors de l'affichage des infos d'un ticket
     */
    DetailsTicket *detailsTicket;
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
    inline GestionnaireDialogue* getGD() const { return gd; }
    /**
     * @brief Affiche l'écran principal de commandes
     */
    void afficherEcranPrincipal();
    /**
     * @brief Mets à jour l'écran principal de commandes
     */
    void mettreAJourEcranPrincipal();
    /**
     * @brief Affiche le Dialog de la création d'un ticket
     */
    void afficherCreationTicket();

    /**
     * @brief Affiche les informations d'un ticket
     * @param ticket Ticket à afficher
     */
    void afficherTicket(Ticket* ticket);

    /**
     * @brief Destructeur de la MainWindow
     */
    ~MainWindow();
};
#endif // MAINWINDOW_H
