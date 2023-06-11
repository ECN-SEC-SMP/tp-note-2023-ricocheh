/**
 * @file Joueur.hpp
 * @brief Définition de la classe Joueur
 */

#pragma once

#include <string>

using namespace std;

/**
 * @class Joueur
 * @brief Représente un joueur dans la partie.
 */
class Joueur {
private:
    string name;         ///< Le nom du joueur
    string shortName;    ///< Le surnom du joueur au cours de la partie
    char remStrokes;     ///< Les coups restants pour le joueur

public:
    Joueur();
    Joueur(string newName, string newShortName);
    char getRemStrokes();
    void setRemStrokes(char strokes);
    void chooseRemStrokes();
    string getName();
    void setName(string newName);
    string getShortName();
    void setShortName(string shortName);
};
