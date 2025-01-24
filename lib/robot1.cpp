#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <robot1.h>
#include <avr/interrupt.h>

volatile bool Robot1::estEnAttente = true;
volatile bool Robot1::estReceptionIR = false;
volatile bool Robot1::estEnvoieRS232 = false;
volatile bool Robot1::estTransmissionDonnees = false;

void Robot1::initialisation(void)
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
    _delay_ms(30);
    Led led_;
    led_.allumerVert();

    if (Robot1::estEnAttente)
    {
        Robot1::estEnAttente = false;
        Robot1::estReceptionIR = true;
    }
    else if (Robot1::estEnvoieRS232)
    {
        Robot1::estEnvoieRS232 = false;
        Robot1::estTransmissionDonnees = true;
    }
}

Robot1::Robot1() : etatActuel(EtatRobot1::ATTENTE) {
    Infrarouge::initialiserTimer();
    SircProtocol sircProtocol;
    sircProtocol.initializeInterrupt();
    sircProtocol.initializeReceptor();
}

void Robot1::afficherDessin()
{
    cli();
    dessin.draw(infrarouge_.longH, infrarouge_.segH, infrarouge_.longB, infrarouge_.segB, estRobot1);
    sei();
}

void Robot1::changerAttente()
{
    initialisation();
    estEnAttente = true;
    estReceptionIR = false;
    while (estEnAttente)
    {
        led_.allumerRouge();
    }

    if (estReceptionIR)
    {
        for (int i = 0; i < 3; ++i)
        {
            son_.emettreSonAigu();
            _delay_ms(50);
            son_.pauseSon();
            _delay_ms(50);
        }
        changerEtat(EtatRobot1::RECEPTION_IR);
    }
}

void Robot1::changerMiseAJourEtat()
{
    switch (etatActuel)
    {
    case EtatRobot1::ATTENTE:
        infrarouge_.estMalRecu = false;
        infrarouge_.estTermineTransmission = false;
        changerAttente();
        break;

    case EtatRobot1::RECEPTION_IR:
        led_.fermer();

        infrarouge_.reception();

        if (infrarouge_.estMalRecu)
        {
            son_.emettreSonGrave();
            changerEtat(EtatRobot1::ATTENTE);
        }
        else
            changerEtat(EtatRobot1::ENVOI_RS232);

        break;

    case EtatRobot1::ENVOI_RS232:
        led_.allumerVert();
        sei();
        if (estTransmissionDonnees)
        {
            changerEtat(EtatRobot1::TRANSMISSION_RS232);
        }
        break;

    case EtatRobot1::TRANSMISSION_RS232:
        afficherDessin();
        estTransmissionDonnees = false;
        estEnvoieRS232 = true;
        infrarouge_.estMalRecu = false;
        infrarouge_.estTermineTransmission = false;
        changerEtat(EtatRobot1::ENVOI_RS232);
        break;
    }
}

void Robot1::changerEtat(EtatRobot1 nouvelEtat)
{
    etatActuel = nouvelEtat;
}
