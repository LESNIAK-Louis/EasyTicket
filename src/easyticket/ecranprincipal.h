#ifndef ECRANPRINCIPAL_H
#define ECRANPRINCIPAL_H

#include <QWidget>

namespace Ui {
class EcranPrincipal;
}

class EcranPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit EcranPrincipal(QWidget *parent = nullptr);
    ~EcranPrincipal();

private slots:
    void on_pushButtonCreationTicket_clicked();

private:
    Ui::EcranPrincipal *ui;
};

#endif // ECRANPRINCIPAL_H
