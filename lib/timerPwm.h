/* INF1900-74 : timerPwm.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de générer un pwm à partir du timer2 et de l'ajuster au besoin. 
   Identifications matérielles: Les broches D6 et D7 sont réservés pour le PWM du timer2 
 * 
*/
#ifndef TIMER1_HPP
#define TIMER1_HPP

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

class TimerPwm {
    public:
        TimerPwm(volatile uint8_t* ddrX, 
        uint8_t pwmPin1, 
        uint8_t pwmPin2,
        uint8_t directionPin1,
        uint8_t directionPin2);
        TimerPwm();
        ~TimerPwm() = default;
        void initialiserSortie(uint8_t valeurPD5, uint8_t valeurPD4);
        void ajusterPwm(uint8_t rapportRoue1, uint8_t rapportRoue2);
    private:
        volatile uint8_t* portX_;
        uint8_t pwmPin1_;
        uint8_t pwmPin2_;
        uint8_t directionPin1_;
        uint8_t directionPin2_;
        
};
#endif