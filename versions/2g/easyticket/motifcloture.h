#ifndef MOTIFCLOTURE_H
#define MOTIFCLOTURE_H

#include "ticket.h"
#include <QDialog>

namespace Ui {

class MotifCloture;
}

/**
 * @brief Classe qui contrôle l'interface de clôture d'un ticket
 * @author Louis LESNIAK
 */
class MotifCloture : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Constructeur
     * @author Louis LESNIAK
     * @param parent Parent
     * @param ticket Ticket à clôturer
     */
    explicit MotifCloture(QWidget *parent = nullptr, Ticket* ticket = nullptr);

    /**
     * @brief Vérifie si les champs sont correctement renseignés
     * @author Louis LESNIAK
     * @return true si les champs sont correctement renseignés
     */
    inline bool getEstValide() const {return this->estValide;}
    ~MotifCloture();

private slots:
    void on_comboBoxResultat_accepted();

private:
    Ui::MotifCloture *ui;
    Ticket* ticket;
    bool estValide;
};



#endif // MOTIFCLOTURE_H
