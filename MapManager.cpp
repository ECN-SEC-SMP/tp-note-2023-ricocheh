/**
 * @file MapManager.cpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

/******* Native include *******/
#include <iostream>
#include <algorithm>

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

Board MapManager::loadBoard(int nb_row, int nb_col) const
{
    cout << "Fonction loadBoard" << endl;
    Board board = Board(nb_row, nb_col);

    addBoardLimit(&board);

    return board;
}

void MapManager::addBoardLimit(Board* board) const
{
    for (auto& cell : board->getCol(0))
    {
        cell->addWall(Cell::WALL_LEFT);
    }

    for (auto& cell : board->getCol(15))
    {
        cell->addWall(Cell::WALL_RIGHT);
    }

    for (auto& cell : board->getRow(0))
    {
        cell->addWall(Cell::WALL_UP);
    }

    for (auto& cell : board->getRow(15))
    {
        cell->addWall(Cell::WALL_DOWN);
    }
}