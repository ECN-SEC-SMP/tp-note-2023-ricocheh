#pragma once
#include <string>

using namespace std;

class Joueur
{
    private:

        string name;         // nom du joueur
        string shortName;    // surnom au cours de la partie
        char remStrokes;     // coups restants
        enum nbJoueurs
        {
            NONE = 0,
            UN_JOUEUR = 1,
            DEUX_JOUEURS = 2,
            TROIS_JOUEURS = 3,
            QUATRES_JOUEURS = 4
        };

    public:

        Joueur();                                       // Constructeur par défaut
        Joueur(string newName, string newShortName);

        char getRemStrokes();
        void setRemStrokes(char strokes);
        void chooseRemStrokes();

        string getName();
        void setName(string newName);

        string getShortName();
        void setShortName(string shortName);
};