#include "SircProtocol.h"
#include "memoire_24.h"
#include "RS232.h"
#include "led.h"
#include <util/delay.h>
#include <avr/interrupt.h>



//volatile bool isClicked = false;
SircProtocol sircProtocol;


void start(){

    uint8_t longH[] = {2, 20, 8};
    uint8_t longB[] = {2, 20, 8};
    uint8_t segH[] = {4, 6, 10};
    uint8_t segB[] = {4, 6, 10};


      uint16_t value = 0;
      uint16_t mask = 0;

       for (int i = 0; i < 3; i++)
       {
         value =  longH[i];
        sircProtocol.turnOn();
        _delay_us(2400);
        sircProtocol.turnOff();
        _delay_us(600);
        for (int i = 0; i < 16; i++)
            {
               mask = 1 << i;

              if((value & mask) != 0) {
                sircProtocol.turnOn();
                _delay_us(1200);
                sircProtocol.turnOff();
                _delay_us(600);
              }else{
                sircProtocol.turnOn();
                _delay_us(600);
                sircProtocol.turnOff();
                _delay_us(600);
              }
            }
        // sircProtocol.turnOn();
        // _delay_us(2400);
        // sircProtocol.turnOff();
        // _delay_us(600);
      } 

      
       

        for (int i = 0; i < 3; i++)
       {
         value =  segH[i];
        sircProtocol.turnOn();
        _delay_us(2400);
        sircProtocol.turnOff();
        _delay_us(600);
        for (int i = 0; i < 16; i++)
            {
               mask = 1 << i;

              if((value & mask) != 0) {
                sircProtocol.turnOn();
                _delay_us(1200);
                sircProtocol.turnOff();
                _delay_us(600);
              }else{
                sircProtocol.turnOn();
                _delay_us(600);
                sircProtocol.turnOff();
                _delay_us(600);
              }
            }
        // sircProtocol.turnOn();
        // _delay_us(2400);
        // sircProtocol.turnOff();
        // _delay_us(600);
      } 

      
        for (int i = 0; i < 3; i++)
       {
         value =  longB[i];
        sircProtocol.turnOn();
        _delay_us(2400);
        sircProtocol.turnOff();
        _delay_us(600);
        for (int i = 0; i < 16; i++)
            {
               mask = 1 << i;

              if((value & mask) != 0) {
                sircProtocol.turnOn();
                _delay_us(1200);
                sircProtocol.turnOff();
                _delay_us(600);
              }else{
                sircProtocol.turnOn();
                _delay_us(600);
                sircProtocol.turnOff();
                _delay_us(600);
              }
            }
        // sircProtocol.turnOn();
        // _delay_us(2400);
        // sircProtocol.turnOff();
        // _delay_us(600);
      } 


        for (int i = 0; i < 3; i++)
       {
         value =  segB[i];
        sircProtocol.turnOn();
        _delay_us(2400);
        sircProtocol.turnOff();
        _delay_us(600);
        for (int i = 0; i < 16; i++)
            {
               mask = 1 << i;

              if((value & mask) != 0) {
                sircProtocol.turnOn();
                _delay_us(1200);
                sircProtocol.turnOff();
                _delay_us(600);
              }else{
                sircProtocol.turnOn();
                _delay_us(600);
                sircProtocol.turnOff();
                _delay_us(600);
              }
            }
        // sircProtocol.turnOn();
        // _delay_us(2400);
        // sircProtocol.turnOff();
        // _delay_us(600);
      } 
       
       Led led;
       led.allumerRouge(); 
            
        //sircProtocol.transmitData(0x08);

 
//}
}

// ISR ( INT0_vect ) {
//     isClicked = !(isClicked);

//     if (isClicked)
//     {
//       start();
//     }
    

// }

bool isClicked(){
    if (PIND & PD4) {
        _delay_ms(10);
        return PIND & PD4;   
    }
    return false;
}

int main(){

//initialisation();
    
       //uint16_t longH[] = {0b0000000000001100, 0b0000000000000110, 0b1111111111111111, 0b0000000000010100, 0b0000000000000001, 0b0000000000011001, 0b0000000000000100, 0b0000000000001111};
       //uint16_t longH[] = {0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B};
    
Led led;

  while (true)
  {
    _delay_ms(100);
   if (isClicked()){
    led.allumerVert();
    _delay_ms(2000);
    start();

}
  }
  

}