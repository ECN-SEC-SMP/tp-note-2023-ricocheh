/**
 * @file Robot.cpp
 * @brief Implémentation de la classe Robot
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 * @author Alexis LEQUEUX <alexis.lequeux@eleves.ec-nantes.fr>
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "Sablier.hpp"

/******* Espace de nommage ****/
using namespace std;

/******* Librairie de temps ****/
#include <chrono>
#include <thread>


/******* Constructeur *******/
/**
 * @brief Initialisation du sablier
 * @param temps temps du sablier en seconde
 */
Sablier::Sablier(int temps)
{
    this->secondes = temps * 1000;
    this->tempsEcoule = 0;
}
/******* STOP *******/
/**
 * @brief Stop le sablier
 */
void Sablier::stop(void)
{
    if (actif) 
    {
        chrono::steady_clock::time_point tempsFin = chrono::steady_clock::now();
        tempsEcoule += chrono::duration_cast<chrono::milliseconds>(tempsFin - tempsDepart).count();
        cout << "Temps: " << tempsEcoule <<endl;
    }
}

/******* START *******/
/**
 * @brief Lance le sablier
 */
void Sablier::start(void)
{
    if (!actif)
    {
        actif = true;
        tempsDepart = chrono::steady_clock::now();
    } 
    else 
    {
        cout << "Deja lance" << endl;
    }
}
/******* RESET *******/
/**
 * @brief Remet à 0 le temps écoulé
 */
void Sablier::reset(void){
    actif = false;
    tempsEcoule = 0;
}

/******* isActive *******/
/**
 * @brief Donne l'état du sablier
 * @return vrai ou faux => ON / OFF
 */
bool Sablier::isActive(void){
    chrono::steady_clock::time_point tempsFinVerif = chrono::steady_clock::now();
    long int tempsActuel = chrono::duration_cast<chrono::milliseconds>(tempsFinVerif - tempsDepart).count();
    if(tempsActuel > secondes)
    {
        this->stop();
        this->reset();
        return false; 
    }
    else if(actif == false)
    {
        return false;
    }
    else
    {
        return true;
    }

}
