/**
 * @file Board.hpp
 * @brief Contient la déclaration de la classe Board.
 */

#pragma once

/******* Include natifs *******/
#include <vector>
#include <set>

/******* Include du projet ******/
#include "Cell.hpp"

/******* Espace de nommage ****/
using namespace std; //Pour ne pas préciser le std devant vector

/**
 * @enum Zone
 * @brief Permet de cibler une zone précise du plateau de jeu.
 */
enum Zone
{
    CENTER = 0,    /**< Zone centrale du plateau. */
    TOP_LEFT,      /**< Coin supérieur gauche du plateau. */
    TOP_RIGHT,     /**< Coin supérieur droit du plateau. */
    BOTTOM_LEFT,   /**< Coin inférieur gauche du plateau. */
    BOTTOM_RIGHT   /**< Coin inférieur droit du plateau. */
};

/**
 * @class Board
 * @brief Classe représentant le plateau de jeu.
 * @details La classe Board permet de stocker l'ensemble des cellules du plateau de jeu.
 */
class Board
{
private:
    vector<vector<Cell>> matrice;   //!< Vecteur 2D de cellules, stockant l'ensemble du plateau de jeu.
    int length;                     //!< Longueur du plateau de jeu (en nombre de cellules).
    int width;                      //!< Largeur du plateau de jeu (en nombre de cellules).

public:
    Board(int nb_row, int nb_col);
    ~Board();
    Cell* getCell(int row, int col);
    vector<vector<Cell*>> getZone(Zone zone);
    vector<Cell*> getCol(int col);
    vector<Cell*> getRow(int row);
    int getLength();
    int getWidth();

    /**
     * @brief Coordonnées des murs sur le plateau de jeu.
     */
    static set<pair<int, int>> wallsCoordinates;
};
