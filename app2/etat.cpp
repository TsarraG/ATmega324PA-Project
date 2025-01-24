#define F_CPU 8000000UL
#include "robot2.h"

int main() {
    Robot2 robot2;
    while (true)
    {
        robot2.changerMiseAJourEtat();
        
    }
}