/**
 * @file Board.cpp
 * @brief Contient l'implémentation de la classe Board.
 */

/******* Include natifs *******/

/******* Include du projet ******/
#include "Board.hpp"

/******* Espace de nommage ****/
using namespace std;

set<pair<int, int>> Board::wallsCoordinatesTl;
set<pair<int, int>> Board::wallsCoordinatesTr;
set<pair<int, int>> Board::wallsCoordinatesBl;
set<pair<int, int>> Board::wallsCoordinatesBr;

/**
 * @brief Renvoie la largeur du plateau de jeu.
 * @return La largeur du plateau de jeu.
 */
int Board::getWidth()
{
    return this->width;
}

/**
 * @brief Renvoie la longueur du plateau de jeu.
 * @return La longueur du plateau de jeu.
 */
int Board::getLength()
{
    return this->length;
}

/**
 * @brief Constructeur de la classe Board.
 * @param nb_row Le nombre de lignes du plateau.
 * @param nb_col Le nombre de colonnes du plateau.
 */
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

/**
 * @brief Destructeur de la classe Board.
 */
Board::~Board()
{

}

/**
 * @brief Récupère la cellule à partir de ses coordonnées.
 * @param x La coordonnée x de la cellule.
 * @param y La coordonnée y de la cellule.
 * @return Un pointeur vers la cellule correspondante.
 */
Cell* Board::getCell(int x, int y)
{
    return &matrice[x][y];
}

/**
 * @brief Récupère une zone spécifique du plateau de jeu.
 * @param zone La zone du plateau à récupérer.
 * @return Un vecteur 2D de pointeurs de cellules représentant la zone demandée.
 */
vector<vector<Cell*>> Board::getZone(Zone zone)
{
    vector<vector<Cell*>> cell_zone;
    int start_row, end_row, start_col, end_col;

    switch(zone)
    {
        case CENTER:
            start_row = (length / 2) - 1;
            start_col = (width / 2) - 1;
            end_row = length / 2;
            end_col = width / 2;
            break;
        case TOP_LEFT:
            start_row = 0;
            start_col = 0;
            end_row = (length / 2) - 1;
            end_col = (width / 2) - 1;
            break;
        case TOP_RIGHT:
            start_row = 0;
            start_col = width / 2;
            end_row = (length / 2) - 1;
            end_col = width - 1;
            break;
        case BOTTOM_LEFT:
            start_row = length / 2;
            start_col = 0;
            end_row = length - 1;
            end_col = (width / 2) - 1;
            break;
        case BOTTOM_RIGHT:
            start_row = length / 2;
            start_col = width / 2;
            end_row = length - 1;
            end_col = width - 1;
            break;
    }

    for(int x = start_row; x <= end_row; x++)
    {
        vector<Cell*> row;
        for(int y = start_col; y <= end_col; y++)
        {
            row.push_back(&matrice[x][y]);
        }
        cell_zone.push_back(row);
    }

    return cell_zone;
}

/**
 * @brief Récupère une colonne spécifique du plateau de jeu.
 * @param col Le numéro de la colonne à récupérer.
 * @return Un vecteur de pointeurs de cellules représentant la colonne demandée.
 */
vector<Cell*> Board::getCol(int col)
{
    vector<Cell*> col_copy;

    for(size_t x = 0; x < matrice.size(); x++)
    {
        for(size_t y = 0; y < matrice[x].size(); y++)
        {
            col_copy.push_back(&matrice[x][col]);
        }
    }

    return col_copy;
}

/**
 * @brief Récupère une ligne spécifique du plateau de jeu.
 * @param row Le numéro de la ligne à récupérer.
 * @return Un vecteur de pointeurs de cellules représentant la ligne demandée.
 */
vector<Cell*> Board::getRow(int row)
{
    vector<Cell*> row_copy;

    for(size_t x = 0; x < matrice[row].size(); x++)
    {
        row_copy.push_back(&matrice[row][x]);
    }

    return row_copy;
}
