/**
 * @file Sablier.hpp
 * @brief La déclaration de la classe Sablier
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

/******* Native include *******/
#include <iostream>
#include <chrono>
/******* Espace de nommage ****/
using namespace std;

/**
 * @brief Déclaration de la classe Sablier
 */
class Sablier
{
    private:
        int secondes; /**< Temps en secondes */
        int tempsEcoule; /**< Temps écoulé en millisecondes */
        chrono::steady_clock::time_point tempsDepart; /**< Moment du lancement du sablier */
        bool actif; /**< État du sablier (activé ou désactivé) */

    public:
        Sablier(int temps);
        void stop(void);
        void start(void);
        void reset(void);
        bool isActive(void);
};
