#include "timer1.h"

Timer1::Timer1(ModeMinuterie mode): mode_(mode){}

void Timer1::partirMinuterie(int16_t duree, int8_t valeurCS10 = 1, int8_t valeurCS11 = 0, int8_t valeurCS12 = 1){
    cli();
    TCNT1 = 0;
    OCR1A = duree;
    TCCR1A = 0;
    if (mode_ == ModeMinuterie::Normal)
        TCCR1B = (valeurCS10 << CS10) |(valeurCS11 << CS11) | (valeurCS12 << CS12);
    else if (mode_ == ModeMinuterie::CTC) 
        TCCR1B = (1<<  WGM12) | (valeurCS10 << CS10) |(valeurCS11 << CS11) | (valeurCS12 << CS12);
    TCCR1C = 0;
    TIMSK1 = (1 << OCIE1A);
    sei();
}