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
     * @param retourne un Qwidget
     */
    explicit EcranPrincipal(QWidget *parent = nullptr);
    void chargerTickets(Utilisateur* utilisateur);

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
};

#endif // ECRANPRINCIPAL_H
