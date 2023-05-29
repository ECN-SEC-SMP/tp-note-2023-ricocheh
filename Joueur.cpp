#include <iostream>
#include "Joueur.hpp"

/**
 * @brief Constructeur par défaut de la classe Joueur
*/
Joueur::Joueur()
{
    switch (nbJoueurs)
    {
    case NONE:
        break;
    case UN_JOUEUR :

        this->name = "Joueur_1";
        this->shortName = "J1";

        this->chooseRemStrokes();
        break;
    case DEUX_JOUEURS :

        this->name = "Joueur_2";
        this->shortName = "J2";

        this->chooseRemStrokes();
        break;
    case TROIS_JOUEURS :

        this->name = "Joueur_3";
        this->shortName = "J3";

        this->chooseRemStrokes();
        break;
    case QUATRES_JOUEURS :

        this->name = "Joueur_4";
        this->shortName = "J4";

        this->chooseRemStrokes();
        break;
    default:
        cout << "Nombre de joueurs supérieur à 4, limites du constructeur par défaut atteintes. Essayez de créer manuellement vos joueurs." << endl;
        return; // possible ? But : ne pas avoir a afficher le message plus bas de résumé de création de personnage.
        break;
    }

    cout << "Ajout d'un nouveau joueur. Nom : " << this->getName() << ". Surnom : " << this->getShortName() << ". Nombre de coups proposé : " << this->getRemStrokes() << ". " << endl;
}

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

    this->setRemStrokes();

    cout << "Ajout d'un nouveau joueur. Nom : " << this->getName() << ". Surnom : " << this->getShortName() << ". Nombre de coups proposé : " << this->getRemStrokes() << ". " << endl;
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

    this->remStrokes = setRemStrokes(newStrokes);
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