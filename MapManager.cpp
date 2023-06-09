/**
 * @file MapManager.cpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

/******* Native include *******/
#include <iostream>
#include <vector>

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

void MapManager::displayBoard(Board b1)
{
    // Get the dimensions of the board
    int width = b1.getWidth();
    int length = b1.getLength();

    // Display the board
    for (int row = 0; row < length; ++row)
    {
        // Display the upper horizontal walls of each cell
        for (int col = 0; col < width; ++col)
        {
            cout << "+";
            const Cell* cell = b1.getCell(row, col);
            if (cell->isWalled(Cell::WALL_UP))
                cout << "----";
            else
                cout << "    ";
        }
        cout << "+" << endl;

        // Display the content of each cell (robot, vertical walls, etc.)
        for (int col = 0; col < width; ++col)
        {
            const Cell* cell = b1.getCell(row, col);
            if (cell->isWalled(Cell::WALL_LEFT))
                cout << "|";
            else
                cout << " ";

            // Display the robot if the cell is taken
            if (cell->isTaken())
                cout << " R ";
            else
                cout << "   ";

            if (cell->isWalled(Cell::WALL_RIGHT))
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Display the lower horizontal walls of each cell
    for (int row = 0; row < length; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            cout << "+";
            const Cell* cell = b1.getCell(row, col);
            if (cell->isWalled(Cell::WALL_DOWN))
                cout << "----";
            else
                cout << "    ";
        }
        cout << "+" << endl;
    }
}

Board MapManager::loadBoard() const
{
    Board b1 = Board(16, 16);
    cout << "loadBoard effectué pour le plateau : " << endl;
    return b1;
}