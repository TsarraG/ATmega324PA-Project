#include "SircProtocol.h"


 const double FREQUENCE = 38000;



 void SircProtocol::initializeProtocol(){
     DDRB |= (1<< PB3);
     PORTB |= (1 << PB3);

     TCCR0A = 0;

     double duration = (F_CPU / (2 * FREQUENCE)) - 1;

     OCR0A = duration;
     TCCR0A = (1 << WGM01) | (1 << COM0A0);
     TCCR0B = (1 << CS00);

     TCCR1C = 0;
 }

 void SircProtocol::transmitData(uint16_t data){
    startBit();
     for (uint8_t i = 6; i >= 0; i--)
     {
        if(data & (1 << i)){
            turnOn();
            _delay_us(1200);
        }else {
            turnOn();
            _delay_us(600);
        }

        turnOff();
        _delay_us(600);
     }
     
     for (uint8_t i = 4; i >= 0; i--)
     {
        if(data & (1 << (i + 7))){
            turnOn();
            _delay_us(1200);
        }else {
            turnOn();
            _delay_us(600);
        }

        turnOff();
        _delay_us(600);
     }
 }

 uint16_t SircProtocol::receiveData() {
    uint16_t data = 0;


 }


 void SircProtocol::initializeReceptor() {
     DDRB &= ~(1 << PB4);
 }

 uint8_t SircProtocol::readSignalReception(){
    return (PINB & (1 << PB4)) ? 1 : 0;
 }


void SircProtocol::turnOn(){
     DDRB |= (1<< PB3);
     PORTB |= (1 << PB3);

     TCCR0A = 0;

     double duration = (F_CPU / (2 * FREQUENCE)) - 1;

     OCR0A = duration;
     TCCR0A = (1 << WGM01) | (1 << COM0A0);
     TCCR0B = (1 << CS00);
     TCCR1C = 0;
}

void SircProtocol::turnOff(){
    TCCR0A &= ~(1 << WGM01);
    TCCR0A &= ~(1 << COM0A0);
    TCCR0B &= ~(1 << CS00);

    OCR0A = 0;
    PORTB &= ~(1 << PB3);
}



void SircProtocol::startBit(){
    turnOn();
    _delay_us(2400);
    turnOff();
    _delay_us(600);
}

void SircProtocol::initializeInterrupt() {
     cli();

    DDRD = 0x00;
    EICRA |= (1 << ISC10);
    EIMSK |= (1 << INT1);

    sei();
 }


 void SircProtocol::startTimer(){
     TCNT1 = 0;
     TCCR1B |= (1 << CS10);
 }

 void SircProtocol::endTimer(){
    TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
    time = TCNT1;
 }



 uint16_t SircProtocol::getTime() {
    return time;
}

