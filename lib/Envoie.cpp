#include "Envoie.h"
#include <avr/io.h>
#include <util/delay.h>

Envoie::Envoie() {}

void Envoie::envoyerTableau(uint8_t *tableau)
{
    uint16_t mask = 0;
    uint16_t value = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        value = tableau[i];
        sircProtocol.turnOn();
        _delay_us(2400);
        sircProtocol.turnOff();
        _delay_us(600);
        for (int i = 0; i < 16; i++)
        {
            mask = 1 << i;
            if ((value & mask) != 0)
            {
                sircProtocol.turnOn();
                _delay_us(1200);
                sircProtocol.turnOff();
                _delay_us(600);
            }
            else
            {
                sircProtocol.turnOn();
                _delay_us(600);
                sircProtocol.turnOff();
                _delay_us(600);
            }
        }
    }
}
