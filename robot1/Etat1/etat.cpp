#define F_CPU 8000000UL
#include "robot1.h"
//#include "deplacement.cpp"

int main() {
    Robot1 robot1;
    while (true)
    {
        robot1.changerMiseAJourEtat();
    }
}