#ifndef CREATION_TICKET_H
#define CREATION_TICKET_H

#include <QDialog>


namespace Ui {
class CreationTicket;
}
/**
 * @brief classe qui permet de crer un ticket dans le GIU
 */
class CreationTicket : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief constructeur de la classe
     * @param parent parent
     */
    explicit CreationTicket(QWidget *parent = nullptr);

    /**
      *destructeur de la classe
      */
    ~CreationTicket();

private slots:
    void on_comboBoxResultat_accepted();

private:
    Ui::CreationTicket *ui;
};

#endif // CREATION_TICKET_H
