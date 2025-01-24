/* INF1900-6674 : Envoie.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina
   Date: 2024-04-17
 * Description du programme: Le but de cette classe est d'utiliser le protocole Sirc afin d'envoyer un tableau contenant les mesures prises
 lors du parcours du robot 2.
*/
#ifndef ENVOIE_H
#define ENVOIE_H

#include "SircProtocol.h"
#include "led.h"

class Envoie
{
private:
  SircProtocol sircProtocol;
  Led led;

public:
  Envoie();
  void envoyerTableau(uint8_t *tableau);
};

#endif
