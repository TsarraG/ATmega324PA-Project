/* INF1900-6674 : deplacement.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina
   Date: 2024-04-17
 * Description du programme: Cette classe utilise les informations du suiveur de ligne afin de suivre le circuit, de tourner aux endroits appropriés,
 d'effectuer le bon type de virage et de prendre les mesures nécessaires au dessin grâce au chronomètre.
.
   Identifications matérielles: Les broches D4 et D5 sont utilisées pour le timer1 du chronomètre, les broches PC2 à PC6 pour le suiveur de ligne et
   les broches D6 ainsi que D7 sont utilisées pour le moteur et le mouvement des roues.
*/
#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <avr/io.h>
#include "timerPwm.h"
#include "moteur.h"
#include "Makerline.h"
#include "timer1.h"
#include "led.h"
#include "chronometre.h"

enum class State
{
    CENTRE,
    GAUCHE,
    DROITE
};

class Deplacement
{
public:
    Deplacement();
    void tournerGauche();
    void tournerDroite();
    void repositionnerDroite();
    void repositionnerGauche();
    void suivreParcours();
    void tournerSegment();
    void tournerVide();
    void tournerSixHuit();
    void tournerQuatre();
    void debloquerRoues();

    Makerline makerline_;
    uint8_t compteurTourne = 0;

    uint8_t indexLongueurHaut = 0;
    uint8_t indexLongueurBas = 0;
    uint8_t indexSegmentHaut = 0;
    uint8_t indexSegmentBas = 0;

    static const int MAX_SIZE = 3;
    uint8_t longueurHaut[MAX_SIZE] = {0, 0, 0};
    uint8_t segmentHaut[MAX_SIZE] = {0, 0, 0};
    uint8_t longueurBas[MAX_SIZE] = {0, 0, 0};
    uint8_t segmentBas[MAX_SIZE] = {0, 0, 0};

    bool estEnHaut = true;
    bool estParcoursFini = false;
    bool estMineturieDebut = false;

private:
    const uint8_t ROUE_D_VITESSE = 56;
    const uint8_t ROUE_G_VITESSE = 50;
    TimerPwm timerPwm_;
    Moteur moteur_ = Moteur::creerInstance(timerPwm_);
    Led led_;
    Chronometre chrono_;
    bool estSurLigne = false;
};

#endif