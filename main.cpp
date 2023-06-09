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
#include "Board.hpp"
#include "MapManager.hpp"

/******* Espace de nommage ****/
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    MapManager* David = MapManager::getInstance();
    Board b1 = Board(16, 16);

    b1.getCell(0, 6)->addWall(Cell::WALL_LEFT);
    b1.getCell(3, 8)->addWall(Cell::WALL_LEFT | Cell::WALL_UP);

    // Affichage du plateau
    David->displayBoard(b1);

    return 0;
}