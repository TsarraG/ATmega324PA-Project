#include "moteur.h"

Moteur::Moteur(TimerPwm timer) : timer_(timer) {}

Moteur Moteur::creerInstance(TimerPwm timer){
    return Moteur(timer);
}

void Moteur::avancer(uint8_t rapport1 = 100, uint8_t rapport2 = 100){

    timer_.initialiserSortie(0,0);
    timer_.ajusterPwm(rapport1, rapport2);
}

void Moteur::reculer(uint8_t rapport1 = 100, uint8_t rapport2 = 100){

    timer_.initialiserSortie(1,1);
    timer_.ajusterPwm(rapport1,rapport2);

}

void Moteur::tournerDroite(uint8_t recule, uint8_t avance){
    timer_.initialiserSortie(0,1);
    timer_.ajusterPwm(recule, avance);
}

void Moteur::tournerGauche(uint8_t avance, uint8_t recule) {
    timer_.initialiserSortie(1,0);
    timer_.ajusterPwm(avance, recule);
}
void Moteur::arreter(){
    timer_.ajusterPwm(0,0);
}