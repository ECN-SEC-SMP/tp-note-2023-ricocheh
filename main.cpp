/*
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Point d'entré du programme
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "Joueur.hpp"
#include "Sablier.hpp"
#include "MapManager.hpp"
#include "Robot.hpp"

/******* Espace de nommage ****/
using namespace std;

int main()
{
    Joueur j1 = Joueur("Robert", "Rob");
    Joueur j2 = Joueur("David", "Dav");

    Board board = MapManager::getInstance()->loadBoard(16, 16);
    Robot yel = Robot(2, 5, JAUNE, &board);
    Robot red = Robot(13, 14, ROUGE, &board);

    //la mécanique des robots est partiellement implémentée, malheuresement nous manquons de temps pour l'intégrer à nos tests.

    MapManager::getInstance()->displayBoard(board);

    Sablier s1(15);
    s1.start();

    return 0;
}