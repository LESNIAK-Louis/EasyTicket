#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include  "ecranprincipal.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

/**
 * @brief Fenêtre de Login, permet à l'utilisateur de se connecter
 * @authors Théo JOFFROY, Louis LESNIAK
 */
class Login : public QWidget
{
    Q_OBJECT

private:
    /**
     * @brief L'UI du Widget Login
     */
    Ui::Login *ui;
    /**
     * @brief Widget EcranPrincipal
     */
    EcranPrincipal* ecranPrincipal;

public:
    /**
     * @brief Constructeur du Widget Login
     * @param parent Parent
     */
    explicit Login(QWidget *parent = nullptr);

    /**
     * @brief Getter du login
     * @return ui->champLogin->text()
     */
    QString const getLogin();

    /**
     * @brief Getter du login
     * @return ui->champMdp->text()
     */
    QString const getPassword();

    /**
     * @brief Réaffiche cette page prêt pour une nouvelle connexion
     * @author Louis LESNIAK
     */
    void deconnexion();

    /**
     * @brief Destructeur du Widget Login
     */
    ~Login();

private slots:
    /**
     * @brief Lorsque le bouton de validation est cliqué, procéder à la vérification du login et affichage de l'EcranPrincipal
     */
    void on_boutonLogin_clicked();


};

#endif // LOGIN_H
