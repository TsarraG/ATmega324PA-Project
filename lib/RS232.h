/* INF1900-74 : RS232.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de contrôler l'accès et l'écriture de la mémoire externe de la carte mère en plus de la transmission 
    de ces données vers l'ordinateur. Ceci facilite les communications internes et externes. 
  Identifications matérielles: Cette classe utilise les broches D0 et D1 pour la transmission de données vers l’ordinateur, 
  C0 et C1 pour la l’échange de données avec la mémoire interne
 *
 * 
*/
#ifndef RS232_H
#define RS232_H

#include <avr/io.h>
#include <string.h>

class Rs232 {
public:
    static Rs232 creerInstance();
    ~Rs232() = default;
    void transmission(uint8_t donnee);
    void transmissionChar(const char* string);
    void initialiserUART();
    uint8_t recevoir();
    
private:
    Rs232();
    static bool estInstancie;

};

#endif 
