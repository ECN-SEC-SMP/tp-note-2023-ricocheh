/**
 * @file Cell.cpp
 * @brief Définition de la classe Cell.
 */

/******* Include natifs *******/

/******* Include du projet ******/
#include "Cell.hpp"

/******* Espace de nommage ****/

/**
 * @brief Constructeur par défaut de la classe Cell.
 */
Cell::Cell()
{
    walls = WALL_EMPTY;
    obj = NONE;
    taken = false;
}

/**
 * @brief Destructeur de la classe Cell.
 */
Cell::~Cell()
{

}

/**
 * @brief Vérifie si la cellule est occupée.
 * @return \c true si la cellule est occupée, \c false sinon.
 */
bool Cell::isTaken() const
{
    return taken ? true : false;
}

/**
 * @brief Vérifie si la cellule a un mur dans une direction donnée.
 * @param wall_direction La direction du mur à vérifier.
 * @return \c true si la cellule a un mur dans la direction donnée, \c false sinon.
 */
bool Cell::isWalled(int wall_direction) const
{
    return walls & wall_direction ? true : false;
}

/**
 * @brief Ajoute un mur à la cellule.
 * @param wall_direction La direction du mur à ajouter.
 */
void Cell::addWall(int wall_direction)
{
    walls |= wall_direction;
}

/**
 * @brief Récupère les murs de la cellule.
 * @return Les murs de la cellule.
 */
int Cell::getWalls() const
{
    return walls;
}

/**
 * @brief Récupère l'objectif de la cellule.
 * @return L'objectif de la cellule.
 */
Objective Cell::getObjective() const
{
    return obj;
}

/**
 * @brief Ajoute un objectif à la cellule.
 * @param objective_type Objectif à ajouter sur la cellule.
 */
void Cell::addObjective(Objective objective_type)
{
    obj = objective_type;
}

/**
 * @brief Définit l'état d'occupation de la cellule.
 * @param state L'état d'occupation à définir.
 */
void Cell::setTaken(bool state)
{
    this->taken = state;
}
