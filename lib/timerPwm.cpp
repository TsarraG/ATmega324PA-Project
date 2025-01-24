#include "timerPwm.h"

TimerPwm::TimerPwm() : pwmPin1_(PD6), pwmPin2_(PD7),
                       directionPin1_(PD5), directionPin2_(PD4)
{
    DDRD |= ((1 << pwmPin1_) | (1 << pwmPin2_) | (1 << directionPin1_) | (1 << directionPin2_));

    TCNT2 = 0;
    ajusterPwm(0, 0);
    TCCR2A = (1 << COM2A1) | (1 << COM2A0) | (1 << COM2B1) | (1 << COM2B0) | (1 << WGM20);
    TCCR2B = (1 << CS21);
}

TimerPwm::TimerPwm(volatile uint8_t *ddrX = &DDRD,
                   uint8_t pwmPin1 = PD6,
                   uint8_t pwmPin2 = PD7,
                   uint8_t directionPin1 = PD5,
                   uint8_t directionPin2 = PD4) : pwmPin1_(pwmPin1), pwmPin2_(pwmPin2),
                                                  directionPin1_(directionPin1), directionPin2_(directionPin2)
{
    *ddrX |= ((1 << pwmPin1_) | (1 << pwmPin2_) | (1 << directionPin1_) | (1 << directionPin2_));

    TCNT2 = 0;
    ajusterPwm(0, 0);
    TCCR2A = (1 << COM2A1) | (1 << COM2A0) | (1 << COM2B1) | (1 << COM2B0) | (1 << WGM20);
    TCCR2B = (1 << CS21);
}

void TimerPwm::initialiserSortie(uint8_t valeurDiretion1, uint8_t valeurDiretion2)
{
    if (valeurDiretion1 == 0)
        PORTD &= ~(1 << directionPin1_);
    else if (valeurDiretion1 == 1)
        PORTD |= (1 << directionPin1_);

    if (valeurDiretion2 == 0)
        PORTD &= ~(1 << directionPin2_);
    else if (valeurDiretion2 == 1)
        PORTD |= (1 << directionPin2_);
}
void TimerPwm::ajusterPwm(uint8_t rapport1, uint8_t rapport2)
{
    uint8_t rapportRoue1 = 100 - rapport1;
    uint8_t rapportRoue2 = 100 - rapport2;
    OCR2A = (rapportRoue1 * 255) / 100;
    OCR2B = (rapportRoue2 * 255) / 100;
}