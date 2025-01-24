/* INF1900-6674 : chronometre.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina
   Date: 2024-04-17
 * Description du programme: Le but de cette classe est de programmer le timer1 de manière à obtenir le temps écoulé lors de différentes situations.
   Identifications matérielles: Les broches D4 et D5 sont utilisées pour le timer1
*/
#ifndef CHRONOMETRE_H
#define CHRONOMETRE_H

#include <avr/io.h>
#include <avr/interrupt.h>

class Chronometre
{
public:
  Chronometre();
  void initChronometre();
  void initChronometrePourIR();
  void commencerChronometre();
  void arreterChronometre();
  uint16_t obtenirTempsEcoule();
  static volatile uint16_t tempsEcoule;
};

#endif
