#include "SircProtocol.h"
#include "memoire_24.h"
#include "RS232.h"
#include "can.h"
#include "chronometre.h"
#include "Drawing.h"
#include "led.h"


int main(){
    
 

    Draw draw; 

    // uint8_t longH[] = {2, 20, 8};
    // uint8_t longB[] = {2, 20, 8};
    // uint8_t segH[] = {4, 6, 10};
    // uint8_t segB[] = {4, 6, 10};

    // uint8_t longH[] = {0x07+5, (0x0C+0x0C)+0x0C,(0x0C+0x36)};
    // uint8_t longB[] = {0x13-3, 0x07+0x13+3, 0x18+0x07+0x13-10};
    // uint8_t segH[] = {8, 6, 0};
    // uint8_t segB[] = {6, 4, 8};

    uint8_t longH[] = {0x08+5, (0x08+5)+0x08+5,(0x08+5)+0x08+5+0x08+5};
    uint8_t longB[] = {42,0, 0};
    uint8_t segH[] = {8, 6, 4};
    uint8_t segB[] = {6, 6, 6};

   draw.draw(longH, segH, longB, segB, true);
   
   
    }
 
  

