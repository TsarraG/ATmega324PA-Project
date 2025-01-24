#include "SircProtocol.h"
#include "memoire_24.h"
#include "RS232.h"
#include "can.h"
#include "chronometre.h"
#include "Drawing.h"
#include "led.h"
#include <avr/interrupt.h>

volatile bool isTimerActivated = false;
volatile uint16_t time = 0;
volatile uint16_t data = 0;
volatile uint8_t counter = 0;
volatile uint16_t times[204];
volatile uint16_t times2[18];
const uint16_t SIRC_START_MIN_US = 2200;
const uint16_t SIRC_START_MAX_US = 3400;
const uint16_t SIRC_BIT_ONE_MIN_US = 7000;
const uint16_t SIRC_BIT_ONE_MAX_US = 20000;
const uint16_t SIRC_BIT_ZERO_MIN_US = 0;
const uint16_t SIRC_BIT_ZERO_MAX_US = 6000;
 Led led;

void initializeTimer(){
    TCNT1 = 0;
    TCCR1B |= (1 << CS10);
}
void startTimer(){
    TCNT1 = 0;
}


void endTimer(){
    time = TCNT1;
    times[counter++] = time;
}

uint16_t convertTime(uint16_t timeToBeConverted){
    return  (timeToBeConverted / 8000000) * 1000000;
}



ISR(INT1_vect){
        isTimerActivated = !(isTimerActivated);
        if (isTimerActivated){
            startTimer();
            led.allumerVert();
        }
        else
        endTimer();
}

// void copyArrayReverse(char* source, char* destination, int size) {
//     for (int i = 0; i < size; ++i) {
//         destination[i] = source[size - i - 1];
//     }
// }




// void transmitData(uint16_t duration) {
//     uint8_t fin;
//     if ((duration >= 7000) && (duration < 16000)) {
//         fin = '1';
//     } else if ((duration >= 0) && (duration < 7000)) {
//         fin = '0';
//     } else if ((duration >= 17000) && (duration < 50000)) {
//         fin = 'S';
//     } else {
//         fin = 'R';
//     }
// }

uint8_t puissance(uint8_t base, uint8_t exposant) {
    uint8_t resultat = 1;
    for (uint8_t i = 0; i < exposant; ++i) {
        resultat *= base;
    }
    return resultat;
}

int main(){
    SircProtocol sircProtocol;
    initializeTimer();
    sircProtocol.initializeInterrupt();
    sircProtocol.initializeReceptor();
 
        Rs232 Rs232 = Rs232::creerInstance();
        uint16_t duration = 0;

   
        while(counter < 204){

        }
        cli();

        led.allumerRouge();

        uint8_t bitData[204];

    //         for (int i = 0; i < 204; i++)
    //    {

    //        duration = times[i];

    //        if((duration >= 7000 )&& (duration < 16000)){
    //            uint8_t fin = '1';
    //            Rs232.transmission(fin);
    //        }else if((duration >= 0) &&( duration < 7000)){
    //            uint8_t fin = '0';
    //            Rs232.transmission(fin);
    //        }else if((duration >= 17000) &&( duration < 50000)){
    //            uint8_t fin = 'S';
    //            Rs232.transmission(fin);
    //        }else{
    //            uint8_t fin = 'R';
    //            Rs232.transmission(fin);

    //        }

    //    }

    uint8_t j = 0;
    for (int i = 203; i >= 0; i--)
       {

           duration = times[i];

           if((duration >= 6000 )&& (duration < 16000)){
              // bitData[j] = '1';
               
              bitData[j] = 1;
           }else if((duration >= 0) &&( duration < 6000)){
               //bitData[j] = '0';
               bitData[j] = 0;
           }else if((duration >= 17000) &&( duration < 50000)){
               //bitData[j] = 'S';
               bitData[j] = 7;
           }else{
               bitData[j] = 9;
           }
        j++;
       }




    // for (uint8_t i = 0; i < 204; i++)
    // {
    //     Rs232.transmission(bitData[i]);
    //     _delay_ms(5);
    // }
    

    //  uint8_t filteredTimes[192];
    

    // for (int i = (startBit + 1); i < 204; i++)
    // {
    //      duration = times[i];

    //     if((i - startBit) % 17 != 0){
    //           if((duration >= 7000 )&& (duration < 16000)){
    //            filteredTimes[i] = 1;
    //            Rs232.transmission(filteredTimes[i]);
    //        }else if((duration >= 0) &&( duration < 7000)){
    //            filteredTimes[i] = 0;
    //            Rs232.transmission(filteredTimes[i]);
    //        }else if((duration >= 17000) &&( duration < 50000)){
    //            filteredTimes[i] = 'S';
    //            Rs232.transmission(filteredTimes[i]);
    //        }else{
    //            filteredTimes[i] = 'R';
    //            Rs232.transmission(filteredTimes[i]);
    //        }
    //     }
         
    // }

   uint8_t taille = sizeof(bitData) / sizeof(bitData[0]);
   uint8_t nouveaubitData[12];
   uint8_t indexNouveaubitData = 0;

   for (uint8_t i = 0; i < 204; i++) {
       if (bitData[i] == 7) {
           uint8_t decimal = 0;
           for (uint8_t j = 0; j < 8; j++) {
               uint8_t valeur = bitData[(i-1) - j];
               decimal += puissance(2, (j)) * valeur;
           }
           nouveaubitData[indexNouveaubitData++] = decimal;
       }
   }

//   for (uint8_t i = 12; i >= 0; i--)
//    {
//        Rs232.transmission(nouveaubitData[i]);
//    }
   

    uint8_t longH[3];
    uint8_t segH[3];
    uint8_t longB[3];
    uint8_t segB[3];


   for (uint8_t i = 0; i < 3; i++)
   {
        longH[i] = nouveaubitData[11 -i];
        segH[i] = nouveaubitData[8 - i];
        longB[i] = nouveaubitData[5 - i];
        segB[i] = nouveaubitData[2 - i];
   }
    

   
    _delay_ms(5);
        for (uint8_t i = 0; i < 3; i++)
    {
        Rs232.transmission(longB[i]);
        _delay_ms(10);
    }

 _delay_ms(5);
        for (uint8_t i = 0; i < 3; i++)
    {
        Rs232.transmission(longH[i]);
        _delay_ms(10);
    }

 _delay_ms(5);
        for (uint8_t i = 0; i < 3; i++)
    {
        Rs232.transmission(segB[i]);
        _delay_ms(10);
    }

    

     longH[1] += longH[0];
     longH[2] += longH[0] + longH[1];

    Draw drawing;
    drawing.draw(longH, segH, longB, segB, true);
// =======
//     //drawing.draw(longH, segH, longB, segB);
        
//     for (uint8_t i = 0; i < 12; i++)
//     {
//         Rs232.transmission(bitData[i]);
//     }
// >>>>>>> Stashed changes
    


}