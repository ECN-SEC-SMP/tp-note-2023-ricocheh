/**
 * @file MapManager.cpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "MapManager.hpp"

/******* Espace de nommage ****/
using namespace std;

MapManager* MapManager::instance = NULL;

MapManager* MapManager::getInstance()
{
    cout << "TODO initialiser le pointeur à null" << endl;
    if (!instance)
        instance = new MapManager;
    return instance;
}

MapManager::MapManager()
{

}

void MapManager::renderBoard() const
{
    cout << "Fonction renderBoard" << endl;
}

void MapManager::loadBoard() const
{
    cout << "Fonction loadBoard" << endl;
}