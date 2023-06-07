/**
 * @file MapManager.hpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */
 #pragma once

 #include "Board.hpp"

/**
 * @class       MapManager
 * @brief       Documentation de la class MapManager
 * @details     La classe \c MapManager permet d'effectuer la création et la manipulaiton du plateau de jeu
 * @author      ASSE Romain <asse-romain@outlook.fr>
 */
class MapManager
{
    private:
        static MapManager *instance;
        MapManager(); //Constructeur privé pour empecher l'instance
        void addBoardLimit(Board *board) const;

    public:
        static MapManager* getInstance();
        Board loadBoard(int nb_row, int nb_col) const;
        void renderBoard() const;
};