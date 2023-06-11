/**
 * @file Cell.hpp
 * @brief Définition de la classe Cell.
 *
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 */

#pragma once

/**
 * @enum Objective
 * @brief Représente les différents objectifs possibles pour une cellule.
 *        NONE : Aucun objectif
 *        RED : Objectif rouge
 *        BLUE : Objectif bleu
 *        GREEN : Objectif vert
 *        YELLOW : Objectif jaune
 *        MULTICOLOR : Objectif multicolore
 */
enum Objective
{
	NONE = 0,
    RED,
	BLUE,
	GREEN,
    YELLOW,
    MULTICOLOR
};

/**
 * @class Cell
 * @brief Représente une cellule du plateau de jeu.
 */
class Cell
{
    private:
        int walls;      //!< Représente les murs de la cellule.
        Objective obj;  //!< Représente l'objectif de la cellule.
        bool taken;     //!< Indique si la cellule est occupée ou non.

    public:
        static const int WALL_EMPTY = 0;         //!< Valeur représentant l'absence de mur.
        static const int WALL_LEFT = 1;          //!< Valeur représentant un mur à gauche.
        static const int WALL_RIGHT = (1 << 1);  //!< Valeur représentant un mur à droite.
        static const int WALL_UP = (1 << 2);     //!< Valeur représentant un mur en haut.
        static const int WALL_DOWN = (1 << 3);   //!< Valeur représentant un mur en bas.

        Cell();
        ~Cell();

        bool isTaken() const;
        bool isWalled(int wall_direction) const;
        void addWall(int wall_direction);
        int getWalls() const;
        Objective getObjective() const;
        void addObjective(Objective objective_type);
        void setTaken(bool state);
};
