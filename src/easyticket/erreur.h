#ifndef ERREUR_H
#define ERREUR_H

#include <QDialog>

namespace Ui {
/**
 * @brief Classe qui contrôle le GUI de la boîte de dialogue d'un message d'erreur
 * @author Louis LESNIAK
 */
class Erreur;
}

class Erreur : public QDialog
{
    Q_OBJECT
private:
    Ui::Erreur *ui;

public:
    /**
     * @brief Constructeur
     * @author Louis LESNIAK
     * @param parent Parent
     */
    explicit Erreur(QWidget *parent = nullptr);
    /**
     * @brief Setter du message d'erreur
     * @author Louis LESNIAK
     * @param erreur Message d'erreur à afficher
     */
    void setErreur(QString erreur);
    ~Erreur();


};

#endif // ERREUR_H
