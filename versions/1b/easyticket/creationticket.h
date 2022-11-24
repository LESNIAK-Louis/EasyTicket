#ifndef CREATION_TICKET_H
#define CREATION_TICKET_H

#include <QDialog>

namespace Ui {
class CreationTicket;
}

class CreationTicket : public QDialog
{
    Q_OBJECT

public:
    explicit CreationTicket(QWidget *parent = nullptr);
    ~CreationTicket();

private:
    Ui::CreationTicket *ui;
};

#endif // CREATION_TICKET_H
