#include "RS232.h"

void Rs232::transmission(uint8_t donnee){
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = donnee;
}

Rs232::Rs232(){
    UBRR0H = 0;
    UBRR0L = 0xCF;

    UCSR0B |= (1 << TXEN0 | 1 << RXEN0) ;
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
};

void Rs232::transmissionChar(const char* string){
    uint16_t length = strlen(string);
    for(uint16_t i= 0; i< length; i++){
        transmission(string[i]);
    }
}
uint8_t Rs232::recevoir(){
    while(!(UCSR0A & (1 << RXC0)));

    return UDR0;
}

Rs232 Rs232::creerInstance() {
    return Rs232();
}
void Rs232::initialiserUART(){
};