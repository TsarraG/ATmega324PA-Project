/* INF1900-6674 : Son.h
<<<<<<< Updated upstream
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina  
   Date: 2024-04-17
=======
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
>>>>>>> Stashed changes

 * Description du programme: Cette classe permet au robot d'emettre des sons.
 *
 * Identifications matérielles:L'émetteur de son utilise PA4 et PA5, qui sont configurés en sortie.
*/

#ifndef SON_H
#define SON_H

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

class Son {
public:
    Son(volatile uint8_t* portX, 
        volatile uint8_t* ddrX, 
        uint8_t pinM, 
        uint8_t pinP); 

    Son();
    void jouer();
    void pauseSon(); 
    void emettreSonGrave(); 
    void emettreSonAigu(); 



private:
    volatile uint8_t* _portX;
    uint8_t _pinM;
    uint8_t _pinP;
    double _force;

};

#endif