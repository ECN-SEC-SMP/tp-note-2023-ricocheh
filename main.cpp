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
#include "Sablier.hpp"

/******* Espace de nommage ****/
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    MapManager* David = MapManager::getInstance();
    Board b1 = Board(16, 16);

    b1.getCell(0, 6)->addWall(Cell::WALL_LEFT);
    b1.getCell(3, 8)->addWall(Cell::WALL_LEFT | Cell::WALL_UP);
    b1.getCell(8, 14)->addWall(Cell::WALL_DOWN | Cell::WALL_UP);

    // Affichage du plateau
    David->displayBoard(b1);

    Sablier s1(15);
    s1.start();
    if(s1.isActive())
    {
        cout << "Le Timer est actif" << endl;
    }
    while(s1.isActive());
    cout<<"FINITO"<<endl;

    return 0;
}