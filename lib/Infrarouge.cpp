#include "Infrarouge.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

Led Infrarouge::led;
uint16_t Infrarouge::duration = 0;
// uint8_t Infrarouge::valeursTransmise[12];

volatile bool Infrarouge::isTimerActivated = false;
volatile uint16_t Infrarouge::time = 0;
volatile uint16_t Infrarouge::data = 0;
volatile uint8_t Infrarouge::counter = 0;
volatile uint16_t Infrarouge::times[204];

void Infrarouge::initialiserTimer()
{
    TCNT1 = 0;
    TCCR1B |= (1 << CS10);
}

void Infrarouge::demarrerTimer()
{
    TCNT1 = 0;
}

void Infrarouge::arreterTimer()
{
    time = TCNT1;
    times[counter++] = time;
}

uint8_t Infrarouge::puissance(uint8_t base, uint8_t exposant)
{
    uint8_t resultat = 1;
    for (uint8_t i = 0; i < exposant; ++i)
    {
        resultat *= base;
    }
    return resultat;
}

ISR(INT1_vect)
{
    Led led;
    led.allumerVert();
    Infrarouge::isTimerActivated = !(Infrarouge::isTimerActivated);
    if (Infrarouge::isTimerActivated)
    {
        Infrarouge::demarrerTimer();
    }
    else
    {
        Infrarouge::arreterTimer();
    }
}

void Infrarouge::reception()
{
    Led led;
    while (counter < 204)
    {
    }

    cli();

    uint16_t tempsBit = 0;
    uint8_t bitData[204];
    uint8_t j = 0;

    for (int i = 203; i >= 0; i--)
    {

        tempsBit = times[i];

        if ((tempsBit >= 6000) && (tempsBit < 16000))
        {
            bitData[j] = 1;
        }
        else if ((tempsBit >= 0) && (tempsBit < 6000))
        {
            bitData[j] = 0;
        }
        else if ((tempsBit >= 17000) && (tempsBit < 50000))
        {
            bitData[j] = 7;
        }
        else
        {
            estMalRecu = true;
            bitData[j] = 9;
        }
        j++;
    }

    uint8_t indexNouveaubitData = 0;
    uint8_t valeursTransmise[12];
    for (uint8_t i = 0; i < 204; i++)
    {
        if (bitData[i] == 7)
        {
            uint8_t decimal = 0;
            for (uint8_t j = 0; j < 8; j++)
            {
                uint8_t valeur = bitData[(i - 1) - j];
                decimal += puissance(2, (j)) * valeur;
            }
            valeursTransmise[indexNouveaubitData++] = decimal;
        }
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        longH[i] = valeursTransmise[11 - i];
        segH[i] = valeursTransmise[8 - i];
        longB[i] = valeursTransmise[5 - i];
        segB[i] = valeursTransmise[2 - i];
    }

    Draw draw;
    if (!estMalRecu)
        draw.draw(longH, segH, longB, segB, true);

    estTermineTransmission = true;
}
