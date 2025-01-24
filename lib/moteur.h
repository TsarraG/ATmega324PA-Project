/* INF1900-6674 : moteur.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de contrôler les mouvements des roues en fonction du pwm. 
   Identifications matérielles: La broche D4 est reliée à la broche D (à gauche) du pont-en-H qui indique le sens de la roue gauche. 
   La broche D5 est reliée à la broche D (à droite) du pont-en-H qui indique le sens de la roue droite. 
   La broche D6 sert de sortie pour le signal PWM de la roue gauche. La broche D7 sert de sortie pour le signal PWM de la roue droite.  
 * 
*/
#ifndef MOTEUR_H
#define MOTEUR_H

#include <avr/io.h>
#include "timerPwm.h"

class Moteur {
    public:
        static Moteur creerInstance(TimerPwm timer);
        void avancer(uint8_t rapport1, uint8_t rapport2);
        void reculer(uint8_t rapport1, uint8_t rapport2);
        void arreter();
        void tournerGauche(uint8_t recule, uint8_t avance);
        void tournerDroite(uint8_t avance, uint8_t reculer);
    private:
        Moteur(TimerPwm timer);
        TimerPwm timer_;
        static bool estInstancie_;

};
#endif