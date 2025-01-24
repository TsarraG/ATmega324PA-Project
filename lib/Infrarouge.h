/* INF1900-6674 : Infrarouge.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Ce programme sert à assurer la reception des données du robot 2 par le robot 1 à l'aide du récepteur infrarouge. 
   Identifications matérielles: Le récepteur infrarouge est connecté au PD3.
*/
#ifndef INFRAROUGE_H
#define INFRAROUGE_H

#include "SircProtocol.h"
#include "led.h"
#include "RS232.h"
#include "Drawing.h"

class Infrarouge {
private:
    static Led led;
    Draw draw;
    static uint16_t duration;

public:
    static volatile bool isTimerActivated;
    static volatile uint16_t time;
    static volatile uint16_t data;
    static volatile uint8_t counter;
    static volatile uint16_t times[204];

    static void initialiserTimer();
    static void demarrerTimer();
    static void arreterTimer();
    static void initialiserInterruption();
    static bool estTimerActive();
    static void transmission(uint8_t donnee);
    void reception();
    static uint8_t puissance(uint8_t base, uint8_t exposant);

    uint8_t longH[3];
    uint8_t segH[3];
    uint8_t longB[3];
    uint8_t segB[3];
    bool estMalRecu = false;
    bool estTermineTransmission = false;
};

#endif // INFRAROUGE_H
