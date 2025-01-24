/* INF1900-74 : timer1.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de contrôler le timer 1 de 16 bits en lui faisant prendre soit le mode CTC
   soit le mode PWM.  
   Identifications matérielles: Les broches D4 et D5 sont réservés pour le pwm du timer1 
 * 
*/
#ifndef TIMER2_HPP
#define TIMER2_HPP

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

enum class ModeMinuterie {
    Normal,
    CTC
};

class Timer1 {
    public:
        ~Timer1() = default;
        Timer1(ModeMinuterie mode);
        void partirMinuterie(int16_t duree, int8_t valeurCS10, int8_t valeurCS11, int8_t valeurCS12);

    private:
        ModeMinuterie mode_;
        
};

 #endif