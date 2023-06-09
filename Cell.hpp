/*
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Déclaration de la classe Cell
 * Cette classe représente la plus petite entité de notre plateau. L'objet cellule représente une case de notre plateau
 */

#pragma once

enum Objective
{
	NONE = 0,
    RED,
	BLUE,
	GREEN,
    YELLOW,
    MULTICOLOR
};

class Cell
{
    private:
        int walls;
        Objective obj;
        bool taken;

    public:
        static const int WALL_EMPTY = 0;
        static const int WALL_LEFT = (1 << 1);
        static const int WALL_RIGHT = (1 << 2);
        static const int WALL_UP = (1 << 3);
        static const int WALL_DOWN = (1 << 4);
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