#ifndef DETAILSTICKET_H
#define DETAILSTICKET_H

#include "messageinfosticket.h"
#include "ticket.h"
#include <QDialog>

namespace Ui {
/**
 * @brief Classe qui contrôle le GUI des détails d'un ticket
 * @author Théo JOFFROY, Louis LESNIAK
 */
class DetailsTicket;
}

/**
 * @brief Affichage des informations d'un ticket
 */
class DetailsTicket : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief constructeur de la classe
     * @author Théo JOFFROY
     * @param parent parent
     * @param ticket
     */
    explicit DetailsTicket(QWidget *parent = nullptr, Ticket* ticket = nullptr);
    ~DetailsTicket();

    /**
     * @brief Affiche les messages correspondants au ticket
     * @author Théo JOFFROY
     */
    void chargerMessages();

private slots:
    void on_boutonEnvoyer_clicked();
    void on_boutonModifierCateg_clicked();
    void on_boutonModifierAttribution_clicked();
    void on_boutonCloturer_clicked();

private:
    Ui::DetailsTicket *ui;
    Ticket* ticket;


};

#endif // DETAILSTICKET_H
