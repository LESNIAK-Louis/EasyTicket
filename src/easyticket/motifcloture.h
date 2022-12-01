#ifndef MOTIFCLOTURE_H
#define MOTIFCLOTURE_H

#include <QDialog>

namespace Ui {
class motifCloture;
}

class motifCloture : public QDialog
{
    Q_OBJECT

public:
    explicit motifCloture(QWidget *parent = nullptr);
    ~motifCloture();

private:
    Ui::motifCloture *ui;
};

#endif // MOTIFCLOTURE_H
