#include <iostream>
using namespace std;

class Sablier {
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