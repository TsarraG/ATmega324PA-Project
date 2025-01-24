#include "led.h"

Led::Led() : portX_(&PORTA), pinM_(PA0), pinP_(PA1)
{
    volatile uint8_t* ddrX = &DDRA;
    *ddrX |= (1 << pinP_); 
    *ddrX |= (1 << pinM_); 
}

Led::Led(volatile uint8_t* portX, volatile uint8_t* ddrX, uint8_t pinM, uint8_t pinP) : 
    portX_(portX), pinM_(pinM), pinP_(pinP)
{
    *ddrX |= (1 << pinP_); 
    *ddrX |= (1 << pinM_); 
}

void Led::allumerRouge(){
    *portX_ |= (1 << pinM_);
    *portX_ &= ~(1 << pinP_);
}

void Led::allumerVert(){
    *portX_ |= (1 << pinP_);
    *portX_ &= ~(1 << pinM_);
}

void Led::allumerAmbre(){
    allumerVert();
    _delay_ms(AMBER_LED_DELAY1);
    allumerRouge();
    _delay_ms(AMBER_LED_DELAY2);
}

void Led::fermer(){
    *portX_ &= ~((1 << pinM_) | (1 << pinP_));
}
