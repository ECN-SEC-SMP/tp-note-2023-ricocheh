/*
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Définition de la classe Cell
 */

/******* Native include *******/

/******* Project include ******/
#include "Cell.hpp"

/******* Espace de nommage ****/

Cell::Cell()
{
    walls = WALL_EMPTY;
    obj = NONE;
    taken = false;
}

Cell::~Cell()
{

}

bool Cell::isTaken() const
{
    return taken ? true : false;
}

bool Cell::isWalled(int wall_direction) const
{
    return walls & wall_direction ? true : false;
}

/**
 * @brief Permet d'ajouter un mur à la cellule
 * @param w Permet d'ajouter un ou plusieurs mur à la cellule (UP ou UP | LEFT)
 */
void Cell::addWall(int wall_direction)
{
    walls |= wall_direction;
}

int Cell::getWalls() const
{
    return walls;
}

Objective Cell::getObjective() const
{
    return obj;
}

/**
 * @brief Permet d'ajouter un objectif à la cellule
 * @param objective_type Objectif à ajouter sur la cellule
 */
void Cell::addObjective(Objective objective_type)
{
    obj = objective_type;
}