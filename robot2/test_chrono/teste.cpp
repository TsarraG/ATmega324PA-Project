#define F_CPU 8000000UL
#include "Makerline.cpp"
#include "chronometre.cpp"
#include "led.cpp"
#include "moteur.cpp"
#include "timerPwm.cpp"



int main() {
    Makerline capteur;
    Chronometre chrono;
    TimerPwm timerPwm_;
    Moteur moteur = Moteur::creerInstance(timerPwm_);
    uint16_t temps;
    Led led;
    chrono.initChronometre();
    chrono.commencerChronometre();
    led.allumerRouge();
    moteur.avancer(50,47);
    while(!(capteur.estTourneDroite()));
    moteur.arreter();
    chrono.arreterChronometre();
    led.allumerVert();
    _delay_ms(2000);
    temps = chrono.obtenirTempsEcoule(); // temps donné en temps * 0.5s

    for (uint8_t i = 0; i < temps; i++){
        led.allumerRouge();
        _delay_ms(400);
        led.fermer();
        _delay_ms(400);
    }

    
}