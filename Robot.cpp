/**
 * @file Robot.cpp
 * @brief Implémentation de la classe Robot
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "Robot.hpp"
#include "Cell.hpp"
#include "Board.hpp"
/******* Espace de nommage ****/
using namespace std;

//************Constructeur************
/**
 * @brief Positionne le robot, enregistre la couleur, occupe une case du plateau de jeu
 * @param x choix de la colonne du jeu
 * @param y choix de la ligne du jeu
 * @param couleur choix de la couleur du robot
 * @param gameBoard passage de l'adresse du plateau de jeu
 */
Robot::Robot(int x, int y, couleur couleurrobot, Board *b1)
{
    this->positionX = x;
    this->positionY = y;
    this->color = couleurrobot;
    Cell* updated; 
    updated = b1->getCell(y, x);
    updated->setTaken(true);
}

/**
 * @brief permet de recuperer la colonne du robot
 * @return colonne du robot
 */
int Robot::getX(void)
{
    return this->positionX;
}

/**
 * @brief permet de recuperer la ligne du robot
 * @return ligne du robot
 */
int Robot::getY(void)
{
    return this -> positionY;
}

/**
 * @brief permet de mettre le robot à une colonne précise du jeu. MàJ du statut occuppé.
 * @param x choix de la colonne du jeu
 * @param b adresse de la board du jeu
 */
void Robot::setX(int x, Board *b)
{ 
    int oldX = this->getX();
    int oldY = this->getY();
    Cell* initial; 
    Cell* updated; 
    initial = b->getCell(oldY,oldX);
    updated = b->getCell(oldY,x);
    initial->setTaken(false);
    updated->setTaken(true);
    this->positionX = x;
}

/**
 * @brief permet de mettre le robot à une ligne précise du jeu. MàJ du statut occuppé.
 * @param y choix de la ligne du jeu
 * @param b adresse de la board du jeu
 */
void Robot::setY(int y,Board *b)
{
    int oldX = this->getX();
    int oldY = this->getY();
    Cell* initial; 
    Cell* updated; 
    initial = b->getCell(oldY,oldX);
    updated = b->getCell(y,oldX);
    initial->setTaken(false);
    updated->setTaken(true);
    this->positionY= y ;
}

/**
 * @brief permet de deplacer le robot dans une des 4 directions. MàJ du statut occuppé.
 * @param direction left right up down
 * @param b1 adresse de la board du jeux 
 */
void Robot::deplacement(sens direction, Board *b1)
{
    if (direction==sens::left)
    {
        int x = this->getX();
        int y = this->getY();
        Cell* initial; 
        Cell* next; 
        initial = b1->getCell(y,x); 
        if (!initial->isWalled(Cell::WALL_LEFT))
        {
            x--;
            while(x>0)
            {
                next = b1->getCell(y,x);
                if(!next->isTaken())
                {
                    if(!next->isWalled(Cell::WALL_RIGHT))
                    {
                        if((!next->isWalled(Cell::WALL_LEFT)))
                        {
                            x--;
                        }
                        else
                        {
                            this->setX(x , b1);
                            return; 
                        }
                    }
                    else
                    {
                        this->setX(x + 1 , b1);
                        return;
                    }
                }
                else
                {
                    this->setX(x + 1 , b1);
                    return;
                } 
            }
            this->setX(0 , b1);
            return;
        }
        this->setX(x , b1);
        return;
    }

    if (direction==sens::right)
    {
        int x = this->getX();
        int y = this->getY();
        Cell* initial; 
        Cell* next; 
        initial = b1->getCell(y,x); 
        if (!initial->isWalled(Cell::WALL_RIGHT))
        {
            x++;
            while(x<16)
            {
                next = b1->getCell(y,x);
                if(!next->isTaken())
                {
                    if(!next->isWalled(Cell::WALL_LEFT))
                    {
                        if((!next->isWalled(Cell::WALL_RIGHT)))
                        {
                            x++;
                        }
                        else
                        {
                            this->setX(x , b1);
                            return; 
                        }
                    }
                    else
                    {
                        this->setX(x - 1 , b1);
                        return;
                    }
                }
                else
                {
                    this->setX(x - 1 , b1);
                    return;
                } 
            }
            this->setX(15 , b1);
            return;
        }
        this->setX(x , b1);
        return;
    }

    if (direction==sens::up)
    {
        int x = this->getX();
        int y = this->getY();
        Cell* initial; 
        Cell* next; 
        initial = b1->getCell(y,x); 
        if (!initial->isWalled(Cell::WALL_UP))
        {
            y++;
            while(y<16)
            {
                next = b1->getCell(y,x);
                if(!next->isTaken())
                {
                    if(!next->isWalled(Cell::WALL_DOWN))
                    {
                        if((!next->isWalled(Cell::WALL_UP)))
                        {
                            y++;
                        }
                        else
                        {
                            this->setY(y , b1);
                            return; 
                        }
                    }
                    else
                    {
                        this->setY(y - 1 , b1);
                        return;
                    }
                }
                else
                {
                    this->setY(y - 1 , b1);
                    return;
                } 
            }
            this->setY(15 , b1);
            return;
        }
        this->setY(y , b1);
        return;
    }

    if (direction==sens::down)
    {
        int x = this->getX();
        int y = this->getY();
        Cell* initial; 
        Cell* next; 
        initial = b1->getCell(y,x); 
        if (!initial->isWalled(Cell::WALL_DOWN))
        {
            y--;
            while(y>0)
            {
                next = b1->getCell(y,x);
                if(!next->isTaken())
                {
                    if(!next->isWalled(Cell::WALL_UP))
                    {
                        if((!next->isWalled(Cell::WALL_DOWN)))
                        {
                            y--;
                        }
                        else
                        {
                            this->setY(y , b1);
                            return; 
                        }
                    }
                    else
                    {
                        this->setY(y + 1 , b1);
                        return;
                    }
                }
                else
                {
                    this->setY(y + 1 , b1);
                    return;
                } 
            }
            this->setY(0 , b1);
            return;
        }
        this->setY(y , b1);
        return;
    }
}
