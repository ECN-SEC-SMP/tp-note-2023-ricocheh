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

/**
 * @brief Obtient l'instance unique de la classe MapManager.
 * @return L'instance unique de MapManager.
 */
MapManager* MapManager::getInstance()
{
    if (!instance)
        instance = new MapManager;
    return instance;
}

/**
 * @brief Constructeur par défaut de la classe MapManager.
 */
MapManager::MapManager()
{

}

/**
 * @brief Affiche le plateau de jeu dans un terminal avec le contenu des cellules (robot, murs, rien ... etc).
 * @param board Le plateau de jeu à afficher.
 */
void MapManager::displayBoard(Board board) const
{
    // Recuperation des dimensions du plateau pour pouvoir iterer sur les colonnes et les lignes
    int width = board.getWidth();
    int length = board.getLength();

    for (int row = 0; row < length; ++row)
    {
        // Affiche la partie horizontale haute de chaque cellule
        for (int col = 0; col < width; ++col)
        {
            cout << "+";
            const Cell* cell = board.getCell(row, col);
            if (cell->isWalled(Cell::WALL_UP))
                cout << "----";
            else
                cout << "    ";
        }
        cout << "+" << endl;

        // Affiche le contenu de chaque cellule (robot, murs verticaux ou horizontaux)
        for (int col = 0; col < width; ++col)
        {
            const Cell* cell = board.getCell(row, col);
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
            const Cell* cell = board.getCell(row, col);
            if (cell->isWalled(Cell::WALL_DOWN))
                cout << "----";
            else
                cout << "    ";
        }
        cout << "+" << endl;
    }
}

/**
 * @brief Charge un plateau de jeu avec le nombre de lignes et de colonnes spécifiées.
 * @param nb_row Le nombre de lignes du plateau.
 * @param nb_col Le nombre de colonnes du plateau.
 * @return Le plateau de jeu chargé.
 */
Board MapManager::loadBoard(int nb_row, int nb_col) const
{
    cout << "Fonction loadBoard" << endl;
    Board board = Board(nb_row, nb_col);

    addBoardLimit(&board);
    addBoardCenter(&board);
    addRandomWall(&board, TOP_LEFT, HORYZONTAL);
    addRandomWall(&board, TOP_LEFT, VERTICAL);
    addRandomWall(&board, TOP_RIGHT, HORYZONTAL);
    addRandomWall(&board, TOP_RIGHT, VERTICAL);
    addRandomWall(&board, BOTTOM_LEFT, HORYZONTAL);
    addRandomWall(&board, BOTTOM_LEFT, VERTICAL);
    addRandomWall(&board, BOTTOM_RIGHT, HORYZONTAL);
    addRandomWall(&board, BOTTOM_RIGHT, VERTICAL);

    addRandomCorner(&board, TOP_LEFT);
    addRandomCorner(&board, TOP_LEFT);
    addRandomCorner(&board, TOP_RIGHT);
    addRandomCorner(&board, TOP_RIGHT);
    addRandomCorner(&board, BOTTOM_LEFT);
    addRandomCorner(&board, BOTTOM_LEFT);
    addRandomCorner(&board, BOTTOM_RIGHT);
    addRandomCorner(&board, BOTTOM_RIGHT);

    return board;
}

/**
 * @brief Ajoute les murs de limite du plateau de jeu.
 * @param board Le plateau de jeu.
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
 * @brief Ajoute les murs du centre du plateau de jeu.
 * @param board Le plateau de jeu.
 */
void MapManager::addBoardCenter(Board* board) const
{
    vector<vector<Cell *>> cells = board->getZone(CENTER);

    for (long unsigned int x = 0; x < cells.size(); x++)
    {
        for (long unsigned int y = 0; y < cells[x].size(); y++)
        {
            cells[x][y]->addWall(Cell::WALL_UP);
            cells[x][y]->addWall(Cell::WALL_DOWN);
            cells[x][y]->addWall(Cell::WALL_LEFT);
            cells[x][y]->addWall(Cell::WALL_RIGHT);
        }
    }
}

/**
 * @brief Ajoute 2 murs aléatoires sur le plateau de jeu.
 * @param board Le plateau de jeu.
 * @param zone La zone du plateau de jeu
 * @param dir la direction du mur à poser
 */
void MapManager::addRandomWall(Board *board, Zone zone, WallDirection dir) const
{
    srand(time(nullptr));
    pair<set<pair<int, int>>::iterator,bool> ret;

    vector<vector<Cell *>> area = board->getZone(zone);

    int xx;
    int yy;

    do
    {
        xx = rand() % area.size();
        yy = rand() % area[0].size();
        pair<int, int> intCoordinate(xx , yy);
        if (zone == TOP_LEFT)
            ret = Board::wallsCoordinatesTl.insert(intCoordinate);
        else if (zone == TOP_RIGHT)
            ret = Board::wallsCoordinatesTr.insert(intCoordinate);
        else if (zone == BOTTOM_LEFT)
            ret = Board::wallsCoordinatesBl.insert(intCoordinate);
        else
            ret = Board::wallsCoordinatesBr.insert(intCoordinate);
    } while(!ret.second);

    int direction = (dir == VERTICAL) ? 1 << (rand() % 2) : 1 << ((rand() % 2) + 2);
    area[xx][yy]->addWall(direction);
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            pair<int, int> forecast(xx + x , yy + y);
            if (zone == TOP_LEFT)
                ret = Board::wallsCoordinatesTl.insert(forecast);
            else if (zone == TOP_RIGHT)
                ret = Board::wallsCoordinatesTr.insert(forecast);
            else if (zone == BOTTOM_LEFT)
                ret = Board::wallsCoordinatesBl.insert(forecast);
            else
                ret = Board::wallsCoordinatesBr.insert(forecast);
        }
    }
}

/**
 * @brief Ajoute des angles sur une zone spécifique du plateau de jeu
 * @param board Le plateau de jeu.
 * @param zone La zone du plateau de jeu
 */
void MapManager::addRandomCorner(Board *board, Zone zone) const
{
    srand(time(nullptr));
    pair<set<pair<int, int>>::iterator,bool> ret;

    vector<vector<Cell *>> area = board->getZone(zone);

    int xx;
    int yy;

    do
    {
        xx = rand() % area.size();
        yy = rand() % area[0].size();
        pair<int, int> intCoordinate(xx , yy);
        if (zone == TOP_LEFT)
            ret = Board::wallsCoordinatesTl.insert(intCoordinate);
        else if (zone == TOP_RIGHT)
            ret = Board::wallsCoordinatesTr.insert(intCoordinate);
        else if (zone == BOTTOM_LEFT)
            ret = Board::wallsCoordinatesBl.insert(intCoordinate);
        else
            ret = Board::wallsCoordinatesBr.insert(intCoordinate);
    } while(!ret.second);

    int dir = rand() % 4;
    int direction = 0;
    if (dir == 0)
        direction = 0b1001;
    else if (dir == 1)
        direction = 0b0101;
    else if (dir == 2)
        direction = 0b1010;
    else
        direction = 0b0110;

    area[xx][yy]->addWall(direction);
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            pair<int, int> forecast(xx + x , yy + y);
            if (zone == TOP_LEFT)
                ret = Board::wallsCoordinatesTl.insert(forecast);
            else if (zone == TOP_RIGHT)
                ret = Board::wallsCoordinatesTr.insert(forecast);
            else if (zone == BOTTOM_LEFT)
                ret = Board::wallsCoordinatesBl.insert(forecast);
            else
                ret = Board::wallsCoordinatesBr.insert(forecast);
        }
    }
}
