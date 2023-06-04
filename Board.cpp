/**
 * @file Board.cpp
 * @brief Contient le plateau de jeu
 */

/******* Native include *******/

/******* Project include ******/
#include "Board.hpp"

/******* Espace de nommage ****/
using namespace std;

Board::Board(int nb_row, int nb_col) : length(nb_row), width(nb_col)
{
    for (int i = 0; i < nb_row; i++)
    {
        vector<Cell> row;
        for (int j = 0; j < nb_col; j++)
        {
            row.push_back(Cell());
        }
        matrice.push_back(row);
    }
}

Board::~Board()
{

}

Cell* Board::getCell(int x, int y)
{
    return &matrice[x][y];
}

/*
 * Si srictement supérieur à 3 et 3, renvoi les 4 cases du milieu
 * Si impair, arrondi inférieur
*/
vector<vector<Cell>> Board::getZone(Zone zone)
{
    vector<vector<Cell>> cell_zone;
    int start_row, end_row, start_col, end_col;

    switch(zone)
    {
        case (CENTER):
            start_row = (length / 2) - 1;
            start_col = (width / 2) - 1;
            end_row = length / 2;
            end_col = width / 2;
            break;
        case (TOP_LEFT):
            start_row = 0;
            start_col = 0;
            end_row = (length / 2) - 1;
            end_col = (width / 2) - 1;
            break;
        case (TOP_RIGHT):
            start_row = 0;
            start_col = width / 2;
            end_row = length - 1;
            end_col = width - 1;
            break;
        case (BOTTOM_LEFT):
            start_row = length / 2;
            start_col = 0;
            end_row = length - 1;
            end_col = (width / 2) - 1;
            break;
        case (BOTTOM_RIGHT):
            start_row = length / 2;
            start_col = width / 2;
            end_row = length - 1;
            end_col = width - 1;
            break;
    }

    for(int x = start_row; x <= end_row; x++)
    {
        for(int y = start_col; y <= end_col; y++)
        {
            
        }
    }

    return cell_zone;
}

vector<Cell> Board::getCol(int col)
{
    vector<Cell> col_copy;
    vector<vector<Cell>>::iterator col_it;

    for(col_it = matrice.begin(); col_it != matrice.end(); col_it++)
    {
        col_copy.push_back((*col_it)[col]);
    }

    return col_copy;
}

vector<Cell> Board::getRow(int row)
{
    return matrice[row];
}