#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <robot2.h>

volatile bool Robot2::estEnAttente = true;
volatile bool Robot2::estEnvoieIR = false;
volatile bool Robot2::estEnvoieRS232 = false;

void Robot2::initialisation(void)
{

    cli();

    DDRD &= ~(1 << PD2);

    EIMSK |= (1 << INT0);

    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC00);

    sei();
}

ISR(INT0_vect)
{
    Led led;
    led.allumerRouge();
    _delay_ms(30);
    Robot2::estEnAttente = false;
    Robot2::estEnvoieIR = true;
}

Robot2::Robot2() : etatActuel(EtatRobot2::EN_TENSION) {}

bool Robot2::estBlancAppuye()
{
    if (!(PINA & MASK_A2))
    {
        _delay_ms(30);
        return !(PINA & MASK_A2);
    }
    return false;
}

void Robot2::envoyerDonnees()
{
    cli();
    for (int i = 0; i < 10; ++i)
    {
        led_.allumerVert();
        _delay_ms(100);
        led_.fermer();
        _delay_ms(100);
    }
    sei();
}

void Robot2::changerEnTension()
{
    while (!deplacement_.estParcoursFini)
    {
        deplacement_.suivreParcours();
    }

    _delay_ms(1000);

    deplacement_.longueurHaut[0] += 5;
    deplacement_.longueurBas[0] += 5;

    deplacement_.longueurHaut[1] += deplacement_.longueurHaut[0];
    deplacement_.longueurBas[1] += deplacement_.longueurBas[0];

    for (uint8_t i = 0; i < 3; i++)
    {
        if (deplacement_.segmentHaut[i] > 8)
            deplacement_.segmentHaut[i] = 7;

        if (deplacement_.segmentBas[i] > 8)
            deplacement_.segmentBas[i] = 7;

        if (deplacement_.longueurHaut[i] > 49)
            deplacement_.longueurHaut[i] = 49;

        if (deplacement_.longueurBas[i] > 49)
            deplacement_.longueurBas[i] = 49;
    }

    if (deplacement_.indexSegmentHaut >= 2)
    {
        deplacement_.longueurHaut[0] = 13;
        deplacement_.longueurHaut[1] = 13 + 13;
        deplacement_.longueurHaut[2] = 13 + 13 + 13;
    }

    if (deplacement_.indexSegmentBas >= 2)
    {
        deplacement_.longueurBas[0] = 13;
        deplacement_.longueurBas[1] = 13 + 13;
        deplacement_.longueurBas[2] = 13 + 13 + 13;
    }

    changerEtat(EtatRobot2::ATTENTE);
}

void Robot2::teste2()
{
    for (uint8_t i = 0; i < 3; i++)
    {
        rs232.transmission(deplacement_.longueurHaut[i]);
        _delay_ms(5);
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        rs232.transmission(deplacement_.segmentHaut[i]);
        _delay_ms(5);
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        rs232.transmission(deplacement_.longueurBas[i]);
        _delay_ms(5);
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        rs232.transmission(deplacement_.segmentBas[i]);
        _delay_ms(5);
    }
}

void Robot2::changerAttente()
{
    initialisation();
    led_.allumerRouge();
    estEnAttente = true;
    estEnvoieIR = false;
    estEnvoieRS232 = false;
    while (estEnAttente)
    {
        if (estBlancAppuye())
        {
            estEnAttente = false;
            estEnvoieRS232 = true;
            cli();
        }
    }

    if (estEnvoieIR)
    {

        for (int i = 0; i < 3; ++i)
        {
            son_.emettreSonAigu();
            _delay_ms(30);
            son_.pauseSon();
        }
        changerEtat(EtatRobot2::ENVOI_IR);
    }

    else if (estEnvoieRS232)
    {
        changerEtat(EtatRobot2::ENVOI_RS232);
    }
}

void Robot2::tester()
{
    for (int i = 0; i < deplacement_.longueurHaut[0]; i += 10)
    {
        led_.allumerVert();
        _delay_ms(300);
        led_.fermer();
        _delay_ms(300);
    }

    led_.allumerRouge();
    _delay_ms(1000);

    for (int i = 0; i < deplacement_.longueurHaut[1]; i += 10)
    {
        led_.allumerVert();
        _delay_ms(300);
        led_.fermer();
        _delay_ms(300);
    }

    led_.allumerRouge();
    _delay_ms(1000);

    for (int i = 0; i < deplacement_.longueurHaut[2]; i += 10)
    {
        led_.allumerVert();
        _delay_ms(300);
        led_.fermer();
        _delay_ms(300);
    }

    led_.allumerVert();
    _delay_ms(1000);

    for (int i = 0; i < deplacement_.segmentHaut[0]; i++)
    {
        led_.allumerRouge();
        _delay_ms(500);
        led_.fermer();
        _delay_ms(500);
    }

    led_.allumerVert();
    _delay_ms(1000);

    for (int i = 0; i < deplacement_.longueurBas[0]; i += 5)
    {
        led_.allumerVert();
        _delay_ms(300);
        led_.fermer();
        _delay_ms(300);
    }

    for (int i = 0; i < deplacement_.longueurBas[1]; i += 5)
    {
        led_.allumerVert();
        _delay_ms(100);
        led_.fermer();
        _delay_ms(100);
    }

    led_.allumerRouge();
    _delay_ms(1000);

    for (int i = 0; i < deplacement_.segmentBas[0]; i++)
    {
        led_.allumerRouge();
        _delay_ms(100);
        led_.fermer();
        _delay_ms(100);
    }
}

void Robot2::changerMiseAJourEtat()
{
    switch (etatActuel)
    {
    case EtatRobot2::EN_TENSION:
        changerEnTension();
        break;

    case EtatRobot2::ATTENTE:
        changerAttente();
        break;

    case EtatRobot2::ENVOI_IR:
        led_.fermer();
        _delay_ms(2000);
        envoie.envoyerTableau(deplacement_.longueurHaut);
        envoie.envoyerTableau(deplacement_.segmentHaut);
        envoie.envoyerTableau(deplacement_.longueurBas);
        envoie.envoyerTableau(deplacement_.segmentBas);
        changerEtat(EtatRobot2::ATTENTE);
        break;

    case EtatRobot2::ENVOI_RS232:
        led_.allumerVert();
        draw.draw(deplacement_.longueurHaut, deplacement_.segmentHaut, deplacement_.longueurBas, deplacement_.longueurBas, estRobot1);
        changerEtat(EtatRobot2::ATTENTE);
        break;
    }
}

void Robot2::changerEtat(EtatRobot2 nouvelEtat)
{
    etatActuel = nouvelEtat;
}