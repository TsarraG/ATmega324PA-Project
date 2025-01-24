#include "Makerline.h"

const uint8_t MASK_SENSORS = (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5) | (1 << PC6);
const uint8_t MASK_S1 =(1 << PC2);
const uint8_t MASK_S2 =(1 << PC3);
const uint8_t MASK_S3 =(1 << PC4);
const uint8_t MASK_S4 =(1 << PC5);
const uint8_t MASK_S5 =(1 << PC6);


Makerline::Makerline(){
    DDRC &= ~MASK_SENSORS;
}

bool Makerline::estMilieuGauche(){
    return (PINC & MASK_S2);
}

bool Makerline::estMilieuDroite(){
    return (PINC & MASK_S4);
}

bool Makerline::estGauche(){
    return (PINC & MASK_S1);
}

bool Makerline::estDroite(){
    return (PINC & MASK_S5);
}

bool Makerline::estLigneCentre(){
    return (PINC & MASK_S3);
}

bool Makerline::estSurLigne(){
    return (PINC & MASK_S1) || (PINC & MASK_S2) || (PINC & MASK_S3) || (PINC & MASK_S4) || (PINC & MASK_S5);
}

bool Makerline::estTourneDroite() {
    return estDroite() && (estLigneCentre() || estMilieuGauche());
}

bool Makerline::estTourneGauche() {
    return estGauche() && (estLigneCentre() || estMilieuDroite());
}

CapteurState Makerline::etatCapteurs() {
    if (estTourneDroite()) {
        return CapteurState::TOURNE_DROITE;
    }
    else if (estTourneGauche()) {
        return CapteurState::TOURNE_GAUCHE;
    }
    else if (estDroite() && !estTourneDroite()) {
        return CapteurState::POUSSE_DROITE;
    }
    else if (estGauche() && !estTourneGauche()) {
        return CapteurState::POUSSE_GAUCHE;
    }
    else {
        return CapteurState::AUCUN;
    }
}