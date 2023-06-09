/**
 * @file Sablier.hpp
 * @brief La déclaration de la classe Sablier
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

/******* Native include *******/
#include <iostream>
/******* Espace de nommage ****/
using namespace std;

/**
 * @brief Déclaration de la classe Sablier
 */
class Sablier 
{
    private:
        int secondes;
        int tempsEcoule;
        chrono::steady_clock::time_point tempsDepart;
        bool actif;

    public:
        Sablier(int temps);
        void stop(void);
        void start(void);
        void reset(void);
        bool isActive(void);
};