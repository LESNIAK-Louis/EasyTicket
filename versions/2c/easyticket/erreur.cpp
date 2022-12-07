#include "erreur.h"
#include "ui_erreur.h"

Erreur::Erreur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erreur)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Erreur");
     ui->labelErreur->setStyleSheet("QLabel { color : red; }");
}

void Erreur::setErreur(QString erreur) { this->ui->labelErreur->setText(erreur);}


Erreur::~Erreur()
{
    delete ui;
}
