#define F_CPU 8000000UL
#include "robot2.h"
#include "deplacement.cpp"
#include <moteur.h>
#include <timerPwm.h>
#include <Son.h>
#include <led.h>


int main() {
    Robot2 robot2;
    TimerPwm pwm;
    Moteur moteur = Moteur::creerInstance(pwm);
    Son son;
    Led led;

    //moteur.tournerGauche(100,100);
    
    while (true)
    {
        robot2.changerMiseAJourEtat();
        
    }
}