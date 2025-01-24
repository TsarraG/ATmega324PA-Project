/* INF1900-6674 : robot2.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est d'implémenter les changements d'états du robot 2 en fonction des différents stades de l'épreuve finale. 
   Identifications matérielles: Les broches D4 et D5 sont utilisées pour le timer1 du chronomètre, les broches PC2 à PC6 pour le suiveur de ligne et 
   les broches D6 ainsi que D7 sont utilisées pour le moteur et le mouvement des roues. La led utilise les ports PA0 et PA1, le son utilise les ports PA4 et PA5
   et les broches C0 et C1 sont réservées pour la mémoire.
*/
#ifndef ROBOT2_H
#define ROBOT2_H

#include <avr/io.h>
#include "deplacement.h"  
#include "led.h"
#include "Son.h" 
#include "Infrarouge.h" 
#include "Envoie.h"
#include "Drawing.h"
#include "RS232.h"




enum class EtatRobot2 {
    EN_TENSION,
    ATTENTE,
    ENVOI_IR,
    ENVOI_RS232
};

class Robot2 {
public:
    Robot2();
    static volatile bool estEnAttente;
    static volatile bool estEnvoieIR;
    static volatile bool estEnvoieRS232;
    
    void changerMiseAJourEtat();
    void changerEtat(EtatRobot2 nouvelEtat);
    bool estBlancAppuye(); 
    void changerEnTension();
    void changerAttente();
    void envoyerDonnees();
    void tester(); 
    void initialisation(void);
    void teste2();
    
    
    Deplacement deplacement_;

private:
    EtatRobot2 etatActuel; 
    Envoie envoie;
    Led led_; 
    uint8_t MASK_A2 = 0x04;
    Son son_;
    Draw draw;
    Rs232 rs232 = Rs232::creerInstance();
    bool estRobot1 = false;
    

};

#endif
