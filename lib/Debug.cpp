
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "RS232.h"
#include "Debug.h"

void printf(char *data)
{
    Rs232 rs232 = Rs232::creerInstance();
    rs232.initialiserUART();
    while (*data)
    {
        rs232.transmission(*data++);
    }
}