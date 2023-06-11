/**
 * @file Robot.hpp
 * @brief La déclaration de la classe Robot.
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

#include "Board.hpp"

/******* Native include *******/
#include <iostream>

/******* Espace de nommage ****/
using namespace std;

/**
 * @enum Couleur
 * @brief Couleurs possibles pour le robot.
 */
enum couleur{JAUNE, VERT, ROUGE, BLEU};

/**
 * @enum Sens
 * @brief Directions possibles pour le déplacement du robot.
 */
enum sens{left, right, up, down};

/**
 * @class Robot
 * @brief Déclaration de la classe Robot.
 * @details La classe Robot représente un robot sur le plateau de jeu. Chaque robot a une position (x, y) et une couleur.
 *          Elle fournit des fonctionnalités pour déplacer le robot et obtenir/modifier sa position.
 */
class Robot
{
private:
    int positionX; /**< Position X du robot. */
    int positionY; /**< Position Y du robot. */
    couleur color; /**< Couleur du robot. */

public:
    Robot(int x, int y, couleur couleurrobot, Board *b1);
    void deplacement(sens direction, Board *b1);
    int getX(void);
    int getY(void);
    void setX(int x, Board *b);
    void setY(int y, Board *b);
};
