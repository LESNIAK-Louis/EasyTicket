#ifndef MESSAGEINFOSTICKET_H
#define MESSAGEINFOSTICKET_H

#include <QWidget>
#include "message.h"

namespace Ui {
class MessageInfosTicket;
}

class MessageInfosTicket : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief constructeur de la classe
     * @param parent QWidget parent
     * @param m Message à afficher
     */
    explicit MessageInfosTicket(QWidget *parent = nullptr, Message* m = nullptr);
    ~MessageInfosTicket();

private:
    Ui::MessageInfosTicket *ui;
};

#endif // MESSAGEINFOSTICKET_H
