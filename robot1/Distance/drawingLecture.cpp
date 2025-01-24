#include "SircProtocol.h"
#include "memoire_24.h"
#include "RS232.h"
#include "can.h"
#include "chronometre.h"
#include "Drawing.h"
#include "led.h"
                            // {0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,   11, 12,   13, 14,  15,  16,  17,  18,  19,  20,  21,  22,  23 };
//const  char* CHARACTERS[] = {" ", "┌", "─", "┐", "└", "┘", "│", "┏", "━", "┓", "┛", "┗", "┃", "╔", "═", "╗", "╝", "╚", "║", " ", "╣", "╦", "╩", "\n"};
//const  char* CHARACTERS[] = {" ", "┌", "-", "┐", "└", "┘", "│", "┏", "-", "-", "┛", "┗", "┃", "╔", "=", "╗", "╝", "╚", "║", " ", "╣", "╦", "╩"};
   //const char* CHARACTERS[] = {"o", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "d", "e", "f", "g", "h", "i", "j", "", "l", "m", "n", "\n"};
                                              

int main(){
    Memoire24CXXX memoire24CXX;
    Rs232 Rs232 = Rs232::creerInstance();
    uint16_t addresse = 0x00;
    uint8_t valeur_lu;
    int value;
        Led led;

    // for (int i = 0; i < sizeof(valeur_lu); i++){
    //       led.allumerRouge();
    //       _delay_ms(200);
    //       led.fermer();
    //       _delay_ms(200);

    // }
    for (int i = 0; i < 200; i++)
    {   
        memoire24CXX.lecture(addresse + i, &valeur_lu);
        _delay_ms(50);
        Rs232.transmissionChar(CHARACTERS[valeur_lu]);
       //Rs232.transmission(valeur_lu);
    
    }
    led.allumerRouge();

    
 
   
  
 }