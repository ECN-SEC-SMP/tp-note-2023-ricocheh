/**
 * ASSE Romain FERRE Cedric, PROCACCIA Paul, LEQUEUX Alexis
 * tp ricochet robots
 *
 * Partie robot
 */

/******* Native include *******/
#include <iostream>

/******* Espace de nommage ****/
using namespace std;
enum couleur{jaune,vert,rouge, bleu};
enum sens{left,right, up, down};

class Robot
{
    private:
        int positionX;
        int positionY;
        couleur color;

    public:

Robot(int x,int y, couleur couleurrobot);
    void deplacement(sens);
    int getX(void);
    int getY(void);
    void setX(int x);
    void setY(int y);
};