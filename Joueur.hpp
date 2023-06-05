#pragma once

#include <string>

using namespace std;

class Joueur
{
    private:

        string name;         // nom du joueur
        string shortName;    // surnom au cours de la partie
        char remStrokes;     // coups restants
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