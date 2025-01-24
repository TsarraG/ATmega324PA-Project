/* INF1900-6674 : SircProtocol.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est d'implémenter le protocole Sirc afin de pouvoir effectuer la transmission de données. 
   Identifications matérielles: Les broches C0 et C1 sont utilisées pour la mémoire et le chronomètre utilise les broches D4 et D5.
*/
#ifndef SIRCPROTOCOL_H
#define SIRCPROTOCOL_H
#define PHOTODETECTOR_PIN PC3
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "chronometre.h"
#include "memoire_24.h"

 class SircProtocol {
 public:
     SircProtocol() = default;
     void initializeProtocol();
     void transmitData(uint16_t data);
     uint16_t receiveData();
     void initializeReceptor();
     uint8_t readSignalReception();
     uint8_t calculateBurst();
     void startBit();
     void turnOff();
     void turnOn();
     void initializeInterrupt();
     volatile uint16_t time;
     void initializeTimer();
     void startTimer();
     void endTimer();
     uint16_t getTime();
    uint8_t receiveData8();
    uint16_t convertTime(uint16_t time);
; private:

     void transmitByte(uint8_t data);

 private:
     uint16_t message;

 };


 #endif
