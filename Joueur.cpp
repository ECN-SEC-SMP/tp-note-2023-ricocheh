#include <iostream>
#include "Joueur.hpp"

/**
 * @brief Constructeur de la classe Joueur
 * @overload
 * @param newName nom a attribuer a l'objet construit
 * @param newShortName surnom a attribuer a l'objet construit
*/
Joueur::Joueur(string newName, string newShortName)
{
    this->name = newName;
    this->shortName = newShortName;

    cout << "Ajout d'un nouveau joueur. Nom : " << this->getName() << ". Surnom : " << this->getShortName() << "." << endl;
}

/**
 * @brief Retourne le nombre coups restants de l'objet appelant cette methode
 * @return remStrokes, le nombre de coups restants du Joueur
*/
char Joueur::getRemStrokes()
{
    return this->remStrokes;
}

/**
 * @brief Definit la valeur des coups restants du joueur
 * @param strokes nombre de coups a inscrire dans l'attribut "coups restants" de l'objet.
 * @return rien
*/
void Joueur::setRemStrokes(char strokes)
{
    this->remStrokes = strokes;
}

/**
 * @brief Permet de choisir son nombre de coups restant
 * @return rien
*/
void Joueur::chooseRemStrokes()
{
    char newStrokes;

    cout << "Veuillez proposer un nombre de coups. : " << endl;
    cin >> newStrokes;

    setRemStrokes(newStrokes);
}

/**
 * @brief Retourne le nom du Joueur
 * @return le nom du Joueur
*/
string Joueur::getName()
{
    return this->name;
}

/**
 * @brief Permet de definir le nom du Joueur
 * @param newName nom a definir
*/
void Joueur::setName(string newName)
{
    this->name = newName;
}

/**
 * @brief Retourne le surnom du joueur
 * @return le surnom du Joueur
*/
string Joueur::getShortName()
{
    return this->shortName;
}

/**
 * @brief Permet de definir le surnom du Joueur
 * @param newShortName surnom a definir
*/
void Joueur::setShortName(string newShortName)
{
    this->shortName = newShortName;
}