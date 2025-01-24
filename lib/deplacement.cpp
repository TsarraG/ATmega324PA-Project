#include "deplacement.h"
#include <util/delay.h>
#include "Debug.h"

Deplacement::Deplacement() {}

void Deplacement::debloquerRoues()
{
    moteur_.avancer(100, 100);
    _delay_ms(100);
    moteur_.arreter();
}

void Deplacement::tournerGauche()
{
    if (compteurTourne >= 4)
    {
        moteur_.arreter();
        _delay_ms(1000);
        debloquerRoues();
        moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE);
        _delay_ms(1000);

        debloquerRoues();
        while (makerline_.estSurLigne())
        {

            moteur_.avancer(0, ROUE_G_VITESSE);
        }

        debloquerRoues();
        while (!(makerline_.estMilieuDroite()))
        {
            moteur_.tournerGauche(ROUE_D_VITESSE - 3, ROUE_G_VITESSE - 3);
        }

        debloquerRoues();
        while (makerline_.estSurLigne())
        {
            moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE);
        }

        moteur_.arreter();
        _delay_ms(500);

        estParcoursFini = true;
    }
}

void Deplacement::tournerDroite()
{
    _delay_ms(500);
    debloquerRoues();
    moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(1000);
    if (makerline_.estSurLigne())
        estSurLigne = true;
    moteur_.tournerDroite(100, 100);
    _delay_ms(20);
    moteur_.tournerDroite(ROUE_D_VITESSE - 5, ROUE_G_VITESSE - 5);
    _delay_ms(400);
    if (makerline_.estSurLigne())
        estSurLigne = true;
    moteur_.tournerGauche(100, 100);
    _delay_ms(75);
    moteur_.tournerGauche(ROUE_D_VITESSE + 10, ROUE_G_VITESSE + 10);
    _delay_ms(500);
    if (makerline_.estSurLigne())
        estSurLigne = true;
    moteur_.tournerGauche(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(50);
    if (makerline_.estSurLigne())
        estSurLigne = true;
    moteur_.tournerDroite(100, 100);
    _delay_ms(75);
    moteur_.tournerDroite(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(400);
    if (makerline_.estSurLigne())
        estSurLigne = true;
    moteur_.reculer(100, 100);
    _delay_ms(50);
    moteur_.reculer(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(400);
    moteur_.arreter();
    _delay_ms(1000);

    if (makerline_.estSurLigne() || estSurLigne)
    {
        estSurLigne = false;
        tournerSegment();

        if (estEnHaut)
            indexLongueurHaut++;
        else
            indexLongueurBas++;

        if (estEnHaut)
            indexSegmentHaut++;
        else
            indexSegmentBas++;

        chrono_.initChronometre();
    }
    else
    {
        tournerVide();
        compteurTourne++;

        if (compteurTourne == 3)
            estEnHaut = false;

        if (compteurTourne == 1 || compteurTourne == 3)
        {
            chrono_.initChronometre();
        }
    }
}

void Deplacement::repositionnerDroite()
{
    // debloquerRoues();
    while (makerline_.estDroite() && !(makerline_.estTourneDroite()))
    {
        moteur_.avancer((ROUE_D_VITESSE + 5), 0);
    }
}

void Deplacement::repositionnerGauche()
{
    // debloquerRoues();
    while (makerline_.estGauche() && !(makerline_.estMilieuGauche()))
    {
        moteur_.avancer(0, (ROUE_G_VITESSE + 5));
    }
}

void Deplacement::tournerVide()
{
    moteur_.avancer(100, 0);
    _delay_ms(50);
    while (!(makerline_.estLigneCentre()))
    {
        moteur_.avancer(ROUE_D_VITESSE + 2, 0);
    }
    moteur_.arreter();
    _delay_ms(500);
    moteur_.avancer(100, 100);
    _delay_ms(30);
}

void Deplacement::tournerQuatre()
{
    debloquerRoues();
    while (makerline_.estSurLigne())
    {
        moteur_.avancer(ROUE_D_VITESSE, 0);
    }
    moteur_.tournerDroite(100, 100);
    _delay_ms(50);
    while (!(makerline_.estMilieuDroite()))
    {
        moteur_.tournerDroite(ROUE_D_VITESSE, ROUE_G_VITESSE);
    }
    moteur_.arreter();
    _delay_ms(500);
    debloquerRoues();
}

void Deplacement::tournerSixHuit()
{
    chrono_.initChronometre();

    debloquerRoues();
    while (makerline_.estSurLigne())
    {
        moteur_.avancer(ROUE_D_VITESSE + 6, ROUE_G_VITESSE + 6);
    }

    chrono_.arreterChronometre();

    moteur_.arreter();

    if (chrono_.obtenirTempsEcoule() <= 10)
    {
        if (estEnHaut)
            segmentHaut[indexSegmentHaut] = 0x06;
        else
            segmentBas[indexSegmentBas] = 0x06;
    }

    else
    {
        if (estEnHaut)
            segmentHaut[indexSegmentHaut] = 0x08;
        else
            segmentBas[indexSegmentBas] = 0x08;
    }

    _delay_ms(1000);
    debloquerRoues();
    moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(1500);
    moteur_.arreter();
    _delay_ms(1000);
    moteur_.tournerGauche(100, 100);
    _delay_ms(50);
    while (!(makerline_.estMilieuGauche()))
    {
        moteur_.tournerGauche(ROUE_D_VITESSE, ROUE_G_VITESSE);
    }

    moteur_.arreter();
    _delay_ms(1000);

    debloquerRoues();
    while (!(makerline_.estTourneGauche()))
    {
        moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE + 4);
    }
    moteur_.arreter();
    _delay_ms(1000);

    debloquerRoues();
    moteur_.avancer(ROUE_D_VITESSE, ROUE_G_VITESSE);
    _delay_ms(1500);

    moteur_.arreter();
    _delay_ms(1000);
    tournerVide();
}

void Deplacement::tournerSegment()
{
    debloquerRoues();
    while (makerline_.estSurLigne())
    {
        moteur_.avancer(ROUE_D_VITESSE + 5, 0);
    }

    chrono_.initChronometre();

    moteur_.tournerDroite(100, 100);
    _delay_ms(50);
    while (!(makerline_.estMilieuGauche()))
    {
        moteur_.tournerDroite(ROUE_D_VITESSE - 7, ROUE_G_VITESSE - 3);
    }

    chrono_.arreterChronometre();

    moteur_.arreter();

    _delay_ms(1000);

    if (chrono_.obtenirTempsEcoule() >= 25)
    {
        tournerQuatre();
        if (estEnHaut)
            segmentHaut[indexSegmentHaut] = 0x04;
        else
            segmentBas[indexSegmentBas] = 0x04;
    }
    else
    {
        tournerSixHuit();
    }
}
void Deplacement::suivreParcours()
{
    switch (makerline_.etatCapteurs())
    {
    case CapteurState::TOURNE_DROITE:
        chrono_.arreterChronometre();
        moteur_.arreter();

        if (estEnHaut)
        {
            longueurHaut[indexLongueurHaut] = chrono_.obtenirTempsEcoule();
        }
        else
        {
            longueurBas[indexLongueurBas] = chrono_.obtenirTempsEcoule();
        }

        tournerDroite();

        break;

    case CapteurState::TOURNE_GAUCHE:
        tournerGauche();
        break;

    case CapteurState::POUSSE_DROITE:
        repositionnerDroite();
        break;

    case CapteurState::POUSSE_GAUCHE:
        repositionnerGauche();
        break;

    default:
        moteur_.avancer((ROUE_D_VITESSE + 8), (ROUE_G_VITESSE + 8));
        break;
    }
}