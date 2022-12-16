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
 * @authors Théo JOFFROY, Aboubacar HASSANE CHEKOU KORE
 */
template <> class Gestionnaire<Utilisateur>
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
    Gestionnaire<Utilisateur>();

    /**
     * @brief Getter d'un utilisateur via son login
     * @param id login de l'utilisateur
     * @return pointeur vers l'utilisateur trouvé, NULL sinon
     */
    Utilisateur& getItem(QString id);

    /**
     * @brief Getter de la QMAP d'utilisateurs
     * @return pointeur vers l'utilisateur trouvé, NULL sinon
     */
    inline QMap<QString,Utilisateur*> getCollection() const {return utilisateurs; }

    /**
     * @brief Ajout d'un utilisateur
     * @param u Utilisateur à ajouter
     */
    void ajouterItem(Utilisateur& u);


    /**
     * @brief Destructeur du gestionnaire d'utilisateurs
     */
    ~Gestionnaire<Utilisateur>();
};

#endif // GESTIONNAIREUTILISATEURS_H
