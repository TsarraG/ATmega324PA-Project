#include "Son.h" 

Son::Son(volatile uint8_t* portX, 
        volatile uint8_t* ddrX, 
        uint8_t pinM, 
        uint8_t pinP) : 
    _portX(portX),
    _pinM(pinM),
    _pinP(pinP)
{
    *ddrX |= (1 << _pinP); 
    *ddrX |= (1 << _pinM); 
}

Son::Son() : 
    _portX(&PORTA),
    _pinM(PA4),
    _pinP(PA5)
{
    DDRA |= (1 << PA4); 
    DDRA |= (1 << PA5);
}


void Son::jouer() {
    *_portX |= (1 << _pinP);
    *_portX &= ~(1 << _pinM);
}

void Son::pauseSon() {
    *_portX &= ~(1 << _pinP);
    *_portX &= ~(1 << _pinM);
} 

void Son::emettreSonGrave() { 
    for (int i = 0; i <= 1000; i++) 
    {
        jouer();
        _delay_ms(4.545);
        pauseSon();
        _delay_ms(4.545); 
    }
}

void Son::emettreSonAigu() { 
    for (uint8_t i = 0; i <=120; i++)
    {
        jouer();
        _delay_ms(0.572);
        pauseSon();
        _delay_ms(0.568);
    }
}