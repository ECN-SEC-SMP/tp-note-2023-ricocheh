/**
 * @file Joueur.hpp
 * @brief Définition de la classe Joueur.
 */

#include <iostream>
#include "Joueur.hpp"

/**
 * @brief Constructeur de la classe Joueur.
 * @overload
 * @param newName Le nom à attribuer à l'objet construit
 * @param newShortName Le surnom à attribuer à l'objet construit
 */
Joueur::Joueur(string newName, string newShortName)
{
    this->name = newName;
    this->shortName = newShortName;

    cout << "Ajout d'un nouveau joueur. Nom : " << this->getName() << ". Surnom : " << this->getShortName() << "." << endl;
}

/**
 * @brief Retourne le nombre de coups restants de l'objet appelant cette méthode.
 * @return Le nombre de coups restants du joueur
 */
char Joueur::getRemStrokes()
{
    return this->remStrokes;
}

/**
 * @brief Définit la valeur des coups restants du joueur.
 * @param strokes Le nombre de coups à inscrire dans l'attribut "coups restants" de l'objet.
 * @return Rien
 */
void Joueur::setRemStrokes(char strokes)
{
    this->remStrokes = strokes;
}

/**
 * @brief Retourne le nom du joueur.
 * @return Le nom du joueur
 */
string Joueur::getName()
{
    return this->name;
}

/**
 * @brief Permet de définir le nom du joueur.
 * @param newName Le nom à définir
 */
void Joueur::setName(string newName)
{
    this->name = newName;
}

/**
 * @brief Retourne le surnom du joueur.
 * @return Le surnom du joueur
 */
string Joueur::getShortName()
{
    return this->shortName;
}

/**
 * @brief Permet de définir le surnom du joueur.
 * @param newShortName Le surnom à définir
 */
void Joueur::setShortName(string newShortName)
{
    this->shortName = newShortName;
}
