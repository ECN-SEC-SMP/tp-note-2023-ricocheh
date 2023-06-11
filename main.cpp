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

/******* Espace de nommage ****/
using namespace std;

int main()
{
    Joueur J1 = Joueur("Robert", "Rob");

    Board b1 = MapManager::getInstance()->loadBoard(16, 16);

    /*for (int x = 0; x < 16; x++)
    {
        for (int y = 0; y < 16; y++)
        {
            cout << b1.getCell(x, y)->getWalls() << endl;
        }
    }*/

    cout << "Hello World!" << endl;

    Sablier s1(15);
    s1.start();
    if(s1.isActive())
    {
        cout << "Le Timer est actif" << endl;
    }
    while(s1.isActive());
    cout<<"FINITO"<<endl;
}