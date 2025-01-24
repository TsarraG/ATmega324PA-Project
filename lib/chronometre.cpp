#include "chronometre.h"

volatile uint16_t Chronometre::tempsEcoule = 0;

Chronometre::Chronometre() {}

void Chronometre::initChronometre()
{
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12);
    TCNT1 = 0;
    OCR1A = 3125;
    TIMSK1 |= (1 << OCIE1A);
    tempsEcoule = 0;
    sei();
}

void Chronometre::commencerChronometre()
{
    tempsEcoule = 0;
    TCNT1 = 0;
    TCCR1B |= (1 << CS12);
}

void Chronometre::arreterChronometre()
{
    TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
}

uint16_t Chronometre::obtenirTempsEcoule()
{
    return tempsEcoule;
}

ISR(TIMER1_COMPA_vect)
{
    Chronometre::tempsEcoule++;
}
