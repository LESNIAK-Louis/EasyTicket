#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H

#include "utilisateur.h"
#include "client.h"
#include "technicien.h"
#include "ingenieur.h"
#include "employe.h"
#include <QMap>

/**
 * @brief Gestionnaire des utilisateurs
 */
class GestionnaireUtilisateurs
{
private:
    /**
     * @brief QMap de la liste des utilisateurs où la clé est l'id de l'utilisateur et la valeur est l'objet utilisateur
     */
    QMap<QString,Utilisateur*> utilisateurs;

public:
    /**
     * @brief Constructeur du gestionnaire d'utilisateurs
     */
    GestionnaireUtilisateurs();

    /**
     * @brief Getter d'un utilisateur via son login
     * @param login
     * @return pointeur vers l'utilisateur trouvé, NULL sinon
     */
    Utilisateur* getUtilisateur(QString login);

    /**
     * @brief Getter de la QMAP d'utilisateurs
     * @return pointeur vers l'utilisateur trouvé, NULL sinon
     */
    inline QMap<QString,Utilisateur*> getUtilisateurs() const {return utilisateurs; }

    /**
     * @brief Ajout d'un utilisateur
     * @param u Utilisateur à ajouter
     */
    void ajouterUtilisateur(Utilisateur* u);


    /**
     * @brief Destructeur du gestionnaire d'utilisateurs
     */
    ~GestionnaireUtilisateurs();
};

#endif // GESTIONNAIREUTILISATEURS_H
