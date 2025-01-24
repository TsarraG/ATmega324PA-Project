/* INF1900-6674 : robot1.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est d'implémenter les changements d'états du robot 1 en fonction des différents stades de l'épreuve finale. 
   Identifications matérielles: Les broches D4 et D5 sont utilisées pour le timer1 du chronomètre, les broches PC2 à PC6 pour le suiveur de ligne et 
   les broches D6 ainsi que D7 sont utilisées pour le moteur et le mouvement des roues. La led utilise les ports PA0 et PA1 et le son utilise les ports PA4 et PA5.
*/
#ifndef ROBOT1_H
#define ROBOT1_H

#include <avr/io.h>
#include "deplacement.h"  
#include "led.h"
#include "Son.h" 
#include "Infrarouge.h"
#include "Drawing.h"

enum class EtatRobot1 {
    ATTENTE,
    RECEPTION_IR,
    ENVOI_RS232, 
    TRANSMISSION_RS232
};

class Robot1 {
public:
    Robot1();
    static volatile bool estEnAttente;
    static volatile bool estReceptionIR;
    static volatile bool estEnvoieRS232; 
    static volatile bool estTransmissionDonnees;
    
    void changerMiseAJourEtat();
    void changerEtat(EtatRobot1 nouvelEtat);
    void changerAttente();
    void afficherDessin();
    //void tester();
    void initialisation(void); 
    
    Deplacement deplacement_;

private:
    EtatRobot1 etatActuel; 
    Led led_; 
    Son son_; 
    Infrarouge infrarouge_;
    Draw dessin;
    bool estRobot1 = true;
    
    

    

};

#endif
