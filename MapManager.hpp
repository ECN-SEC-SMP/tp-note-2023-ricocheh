/**
 * @file MapManager.hpp
 * @brief Permet de créer, gérer et afficher le plateau de jeu.
 */
 #pragma once

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

    public:
        static MapManager* getInstance();
        void loadBoard() const;
        void renderBoard() const;
};