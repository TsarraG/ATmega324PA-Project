/* INF1900-74 : Makerline.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est d'implémenter les comportements voulus dépendemment
   de quels senseurs du capteur sont activés. 
   Identifications matérielles: Les broches PC2 à PC6 sont réservées pour le suiveur de ligne.
 * 
*/
#ifndef MAKERLINE_H
    #define MAKERLINE_H

#include <avr/io.h> 

enum class CapteurState {
    TOURNE_DROITE,
    TOURNE_GAUCHE,
    POUSSE_DROITE,
    POUSSE_GAUCHE,
    AUCUN
};


class Makerline{
public:
  Makerline();

  bool estTourneDroite();
  bool estTourneGauche();
  bool estMilieuGauche(); 
  bool estMilieuDroite();
  bool estGauche();
  bool estDroite();
  bool estLigneCentre();
  bool estSurLigne();
  CapteurState etatCapteurs();


};
#endif