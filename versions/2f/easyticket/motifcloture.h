#ifndef MOTIFCLOTURE_H
#define MOTIFCLOTURE_H

#include "ticket.h"
#include <QDialog>

namespace Ui {
class MotifCloture;
}

class MotifCloture : public QDialog
{
    Q_OBJECT

public:
    explicit MotifCloture(QWidget *parent = nullptr, Ticket* ticket = nullptr);
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
