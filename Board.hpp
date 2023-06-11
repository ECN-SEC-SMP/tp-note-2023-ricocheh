/**
 * @file Board.hpp
 * @brief Contient la déclaration de la classe Board.
 */
#pragma once

/******* Native include *******/
#include <vector>
#include <set>

/******* Project include ******/
#include "Cell.hpp"

/******* Espace de nommage ****/
using namespace std; //Pour ne pas préciser le std devant vector

/**
 * @enum Zone
 * @brief Permet de cibler une Zone du plateau de jeu précise
 */
enum Zone
{
	CENTER = 0,
    TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
    BOTTOM_RIGHT
};

/**
 * @class       Board
 * @brief       Documentation de la class Board
 * @details     La classe \c Board permet stocker l'ensemble des cellules du plateau de jeu.
 * @author      ASSE Romain <asse-romain@outlook.fr>
 */
class Board
{
    private:
        vector<vector<Cell>> matrice; //!< vecteur 2d de Cellules, stocke l'ensemble du plateau de jeu
        int length; //!< Longueur du plateau de jeu (en nombre de cellule)
        int width; //!< Largeur du plateau de jeu (en nombre de cellule)
    public:
        Board(int nb_row, int nb_col);
        ~Board();
        Cell* getCell(int row, int col);
        vector<vector<Cell *>> getZone(Zone zone);
        vector<Cell *> getCol(int col);
        vector<Cell *> getRow(int row);
        static set<pair<int, int>> wallsCoordinates;
};