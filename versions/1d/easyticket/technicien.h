#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "employe.h"

/**
 * @brief represente un technicien dans l'application
 */
class Technicien : public Employe
{
public:
    /**
     * @brief Constucteur d'un Technicien
     * @param login  d'un Technicien
     * @param nom d'un Technicien
     * @param prenom d'un Technicien
     */
    Technicien(QString login, QString nom, QString prenom);

    /**
     * @brief retourne vrai si c'est l'employé est un technicien
     * @return valeur du bool
     */
    bool estUnTechnicien() const;

    /**
     * @brief destructeur de la classe
     */
    ~Technicien();
};

#endif // TECHNICIEN_H
