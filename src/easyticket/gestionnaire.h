#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <QMap>

/**
 * @brief classe qui encapsule une collection d'objets génériques
 * @authors Théo JOFFROY
 */
template <class T> class Gestionnaire
{
private:

    /**
     * @brief table (clé = id, T) qui gere la collection de données
     * @author Théo JOFFROY
     */
    QMap<int,T*> collection;

public:
    Gestionnaire();

    /**
     * @brief renvoie la collection entière
     * @author Théo JOFFROY
     * @return la collection
     */
    QMap<int,T*> getCollection();

    /**
     * @brief renvoie un item de la collection
     * @author Théo JOFFROY
     * @param id identifiant de l'item
     * @return retourne l'item
     */
    T& getItem(int id);

    /**
     * @brief ajoute un item dans son gestionnaire
     * @author Théo JOFFROY
     * @param item item a ajouter
     */
    void ajouterItem(T& item);
};

#endif // GESTIONNAIRE_H
