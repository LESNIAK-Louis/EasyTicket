#ifndef ERREUR_H
#define ERREUR_H

#include <QDialog>

namespace Ui {
class Erreur;
}

class Erreur : public QDialog
{
    Q_OBJECT
private:
    Ui::Erreur *ui;

public:
    explicit Erreur(QWidget *parent = nullptr);
    void setErreur(QString erreur);
    ~Erreur();


};

#endif // ERREUR_H
