/* INF1900-6674 : led.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de programmer la DEL de manière à ce que celle-ci puisse s'allumer en vert, en rouge, prendre la couleur ambre et s'éteindre.
 *
 * Identifications matérielles: Nous pouvons choisir n'importe quel port libre que nous désirons.
*/
#ifndef LED_HPP
#define LED_HPP
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h> 
class Led {
    public:
        Led();
        Led(volatile uint8_t* portX, volatile uint8_t* ddrX, uint8_t pinM, uint8_t pinP);
        ~Led() = default;
        void allumerRouge();
        void allumerVert();
        void allumerAmbre();
        void fermer();
    private:
        volatile uint8_t* portX_;
        uint8_t pinM_;
        uint8_t pinP_;
        static constexpr uint8_t AMBER_LED_DELAY1 = 10;
        static constexpr uint8_t AMBER_LED_DELAY2 = 2;
        
};
#endif