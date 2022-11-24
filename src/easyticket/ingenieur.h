#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "employe.h"

/**
 * @brief la classe qui represente un ingénieur
 */
class Ingenieur :  public Employe
{
public:

    /**
     * @brief constructeur d'un ingenieur
     * @param login d'un ingenieur
     * @param nom d'un ingenieur
     * @param prenom d'un ingenieur
     */
    Ingenieur(QString login, QString nom, QString prenom);

    /**
     * @brief retourne vrai si c'est un ingenieur
     * @return valeur du bool
     */
    bool estUnIngenieur() const;

    /**
     * @brief destructeur pour la classe
     */
    ~Ingenieur();
};

#endif // INGENIEUR_H
