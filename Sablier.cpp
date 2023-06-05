/**
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Partie gestion du temps - Sablier
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

//************METHODE************
/*
Le Sablier est implemente avec la methode suivante. Nous utilisons un chrono que l'on lance avec la fonction start,
que l'on arrete avec la focntion stop et que l'on remet a 0 avec la fonciton reset

Lorsque l'on utilise la fonction isActif cette fonction va nous dire si il est actif (Sablier en cours)
Ou bien si il n'est pas actif qui se traduit par deux situations possibles:
-Le Sablier n'a pas ete lance 
-Le temps imparti est ecoule
*/


//************Constructeur************
Sablier::Sablier(int temps){
this->secondes=temps*1000;// enregistrement du temps en ms
this->tempsEcoule=0;//mise a 0 du temps ecoule
}
//************STOP************
void Sablier::stop(void){
if (actif) {
            chrono::steady_clock::time_point tempsFin =chrono::steady_clock::now();//memorisation du temps de fin
            tempsEcoule += chrono::duration_cast<chrono::milliseconds>(tempsFin - tempsDepart).count();//calcul du temps
            actif = false;//desactivation du Sablier
            cout << "Temps: " << tempsEcoule <<endl;// affichage du temps
        }
}

//************START************
void Sablier::start(void){
    if (!actif) // si le Sablier n'est pas lancé
    {
        actif = true;//passage à l'état actif
        tempsDepart = chrono::steady_clock::now();//lancement du chrono et memorisation du temps de départ
    } else 
    {
                cout << "Deja lance" << endl;//message d'erreur si le Sablier est actif
    }
}
//************RESET************
void Sablier::reset(void){
    actif = false;// descativation du Sablier
    tempsEcoule=0;//mise a 0 du temps ecoule
}

//************ETAT DU SABLIER************
bool Sablier::isActive(void){
    chrono::steady_clock::time_point tempsFinVerif =chrono::steady_clock::now();//calcul du temps restant du Sablier
    long int tempsActuel = chrono::duration_cast<chrono::milliseconds>(tempsFinVerif - tempsDepart).count();//calcul du temps restant du Sablier
    if(tempsActuel>secondes){// si le temps depasse la valeur du Sablier => Sablier termine
        this->stop(); //on arrete
        this->reset(); //on remet a 0
        return false; // retourne faux (pas de Sablier actif, car il est fini)
    }
    else if(actif==false){// si le Sablier n'est pas actif (stop ou reset)
        return false; // retourne faux
    }
    else{
        return true; // sinon il est actif, on retourne actif
    }

}
