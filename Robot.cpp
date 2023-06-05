/**
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Partie Robot
 */

/******* Native include *******/
#include <iostream>

/******* Project include ******/
#include "Robot.hpp"

/******* Espace de nommage ****/
using namespace std;

//************Constructeur************
Robot::Robot(int x,int y, couleur couleurrobot){
    this->positionX=x;
    this->positionY=y;
    this->color=couleurrobot;
}

int Robot::getX(void){
    return this->positionX;
}
int Robot::getY(void){
    return this->positionY;
}
void Robot::setX(int x){ //ajouter un test pour savoir si on peut ajouter le pion à cette case
    this->positionX=x; // compliquer du fait de la séparation du X et du Y
}
void Robot::setY(int y){//ajouter un test pour savoir si on peut ajouter le pion à cette case
    this->positionY=y;// compliquer du fait de la séparation du X et du Y
}
void Robot::deplacement(enum sens){
/*
if (sens==1){//gauche
    int a = this->getX;

while(a>0 && !a.isWall){
    a--;
}
this->setX(a);
}

if (sens==2){//droite
    int a = this->getX;

while(a<MAXligne && !a.isWall){
    a++;
}
this->setX(a);
}

if (sens==3){//haut
    int a = this->getY;

while(a<MAXligne && !a.isWall){
    a++;
}
this->setY(a);
}

if (sens==4){//bas
    int a = this->getY;

while(a>0 && !a.isWall){
    a--;
}
this->setY(a);

*/ 
}