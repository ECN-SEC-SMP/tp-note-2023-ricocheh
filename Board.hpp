/**
 * @file Board.hpp
 * @brief Contient le plateau de jeu
 */
#pragma once

#include <vector>

#include "Cell.hpp"

using namespace std; //Pour ne pas préciser le std devant vector

enum Zone
{
	CENTER = 0,
    TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
    BOTTOM_RIGHT,
};

/**
 * @class       MapManager
 * @brief       Documentation de la class MapManager
 * @details     La classe \c Board permet d'effectuer la création et la manipulaiton du plateau de jeu
 * @author      ASSE Romain <asse-romain@outlook.fr>
 */
class Board
{
    private:
        vector<vector<Cell>> matrice;
        int length;
        int width;
    public:
        Board(int nb_row, int nb_col);
        ~Board();
        Cell* getCell(int row, int col);
        vector<vector<Cell>> getZone(Zone zone);
        vector<Cell> getCol(int col);
        vector<Cell> getRow(int row);
};