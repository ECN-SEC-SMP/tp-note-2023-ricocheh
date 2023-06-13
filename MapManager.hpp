/**
 * @file MapManager.hpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */

#pragma once

#include "Board.hpp"

/**
 * @class MapManager
 * @brief Documentation de la classe MapManager
 * @details La classe \c MapManager permet d'effectuer la création et la manipulation du plateau de jeu.
 *          Elle fournit des fonctionnalités pour ajouter des limites, un centre, des murs aléatoires et des coins au plateau de jeu.
 * @author ASSE Romain <asse-romain@outlook.fr>
 */
class MapManager
{
private:
    static MapManager *instance;
    MapManager(); // Constructeur privé pour empêcher l'instanciation directe.
    void addBoardLimit(Board *board) const;
    void addBoardCenter(Board* board) const;
    void addRandomWall(Board* board, Zone zone, WallDirection dir) const;
    void add2RandomCorner(Board* board) const;

public:
    static MapManager* getInstance();
    Board loadBoard(int nb_row, int nb_col) const;
    void displayBoard(Board board) const;
};
