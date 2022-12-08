#ifndef ECRANPRINCIPAL_H
#define ECRANPRINCIPAL_H

#include <QWidget>
#include <QListWidgetItem>
#include "utilisateur.h"

namespace Ui {
class EcranPrincipal;
}

/**
 * @brief la classe pour l'ecran principale
 */
class EcranPrincipal : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe
     * @param parent parent
     */
    explicit EcranPrincipal(QWidget *parent = nullptr);

    /**
     * @brief Charge les tickets de l'utilisateur et les affiche à l'écran
     * @param utilisateur Utilisateur dont on veut charger les tickets
     */
    void chargerTickets();

    /**
     * @brief Getter de l'utilisateur
     * @return utilisateur
     */
    inline Utilisateur* getUtilisateur() const {return utilisateur;}

    ~EcranPrincipal();

private slots:

    /**
     * @brief fonction qui creer un ticket quand son bouton equivalent est clické
     */
    void on_pushButtonCreationTicket_clicked();

    void on_listeTickets_itemClicked(QListWidgetItem *item);

private:
    /**
     * @brief interface de l'ecran principale
     */
    Ui::EcranPrincipal *ui;
    Utilisateur* utilisateur;
};

#endif // ECRANPRINCIPAL_H
