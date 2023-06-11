/**
 * @file MapManager.cpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

/******* Native include *******/
#include <iostream>
#include <vector>
#include <algorithm>

/******* Project include ******/
#include "MapManager.hpp"
#include "Cell.hpp"

/******* Espace de nommage ****/
using namespace std;

MapManager* MapManager::instance = NULL;

MapManager* MapManager::getInstance()
{
    if (!instance)
        instance = new MapManager;
    return instance;
}

MapManager::MapManager()
{

}

/**
 *@brief Affiche le plateau de jeu dans un terminal avec le contenu des cellules (robot, murs, rien ... etc)
 *@param b1 Plateau de jeu à afficher
*/
void MapManager::displayBoard(Board b1)
{
    // Recuperation des dimensions du plateau pour pouvoir iterer sur les colonnes et les lignes
    int width = b1.getWidth();
    int length = b1.getLength();

    for (int row = 0; row < length; ++row)
    {
        // Affiche la partie horizontale haute de chaque cellule
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

        // Affiche le contenu de chaque cellule (robot, murs verticaux ou horizontaux)
        for (int col = 0; col < width; ++col)
        {
            const Cell* cell = b1.getCell(row, col);
            if (cell->isWalled(Cell::WALL_LEFT))
                cout << "|";
            else
                cout << " ";

            // Affiche un robot si la cellule est occupée
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

        // Affiche la partie horizontale basse de chaque cellule
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

/**
 * @brief Permet de générer les murs faisant le pourtour du plateau de jeu
 * @param Prend le plateau de jeu dont on veut créer les limites
*/
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

/**
 * @brief Permet de générer un plateau du nombre de lignes et de colones souhaité
 * @param nb_row Nombre de lignes souhaité
 * @param nb_col Nombre de colones souhaité
*/
Board MapManager::loadBoard(int nb_row, int nb_col) const
{
    cout << "Fonction loadBoard" << endl;
    Board board = Board(nb_row, nb_col);

    addBoardLimit(&board);

    return board;
}