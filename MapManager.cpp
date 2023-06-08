/**
 * @file MapManager.cpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "MapManager.hpp"
#include "Cell.hpp"

/******* Espace de nommage ****/
using namespace std;

MapManager* MapManager::instance = NULL;

MapManager* MapManager::getInstance()
{
    //cout << "TODO initialiser le pointeur à null" << endl;
    if (!instance)
        instance = new MapManager;
    return instance;
}

MapManager::MapManager()
{

}

void MapManager::renderBoard(Board b1)
{
    int mapX = b1.getWidth();
    int mapY = b1.getLength();

    for (int i = 0; i < mapX; i++)
    {
        for (int j = 0; j < mapY; j++)
        {
            if (b1.getCell(i, j)->getWalls() & Cell::WALL_UP)    { cout <<  "^"; }
            if (b1.getCell(i, j)->getWalls() & Cell::WALL_DOWN)  { cout <<  "_"; }
            if (b1.getCell(i, j)->getWalls() & Cell::WALL_LEFT)  { cout << "L";  }
            if (b1.getCell(i, j)->getWalls() & Cell::WALL_RIGHT) { cout << "R";  }
            if (b1.getCell(i, j)->isTaken())                     { cout <<  "@"; }
        }
        cout << endl;
    }
    cout << "Fonction renderBoard" << endl;
}

Board MapManager::loadBoard() const
{
    Board b1 = Board(16, 16);
    cout << "loadBoard effectué pour le plateau : " << endl;
    return b1;
}