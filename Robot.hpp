/**
 * @file Robot.hpp
 * @brief La déclaration de la classe Robot
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

/******* Native include *******/
#include <iostream>
#include "Board.hpp"

/******* Espace de nommage ****/
using namespace std;

/**
 * @enum Couleur
 * @brief Couleur possible que le robot peut avoir
 */
enum couleur{jaune, vert, rouge, bleu};

/**
 * @enum Sens
 * @brief Différent sens dans lequel on peut déplacer le robot
 */
enum sens{left, right, up, down};

/**
 * @brief Déclaration de la classe Robot
 */
class Robot
{
    private:
        int positionX;
        int positionY;
        couleur color;

    public:
        Robot(int x,int y, couleur couleurrobot, Board *b1);
        void deplacement(sens direction, Board *b1);
        int getX(void);
        int getY(void);
        void setX(int x, Board *b);
        void setY(int y, Board *b);
};