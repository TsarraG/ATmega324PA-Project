#define F_CPU 8000000UL
//#include "deplacement.h"
#include "robot2.h"

int main() {
    //Deplacement deplacement;
    Robot2 robot2;
    while (true) {
         //deplacement.resterDroit();
       //deplacement.suivreParcour();
        //deplacement.test();
        //deplacement.suivreParcours();
        robot2.changerMiseAJourEtat();
        
    }
    //deplacement.suivreParcour();
    
    
}