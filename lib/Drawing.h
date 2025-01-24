/* INF1900-6674 : Drawing.h
 * Nom des auteurs: Anders Antoine,  Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17 
 * Description du programme: Le but de cette classe est de produire un dessin issu du tracé de ligne effectué par le robot 2. 
   Identifications matérielles: La mémoire est utilisée pour ce processus, donc les broches C0 et C1 sont sollicitées.
*/
#ifndef DRAWING_H
#define DRAWING_H

#include "memoire_24.h"
#include "RS232.h"
#include "led.h"
#include "Constantes.h"
#include <avr/io.h>

struct Canvas {
    static const uint8_t width = 80;
    static const uint8_t height = 20;
    uint8_t drawing[height][width+1];
    uint8_t decodedDrawing[width* (width+1) + (height-1)];
};

class Draw {


public:
    Draw();
    uint8_t drawBox2(int i, int j, uint8_t longueurHaut[3], uint8_t segmentHaut[3], uint8_t longueurBas[3], uint8_t segmentBas[3], bool estRobot1);
    const char* CHARACTERS[27] = {" ", "┌", "─", "┐", "└", "┘", "│", 
    "┏", "━", "┓", "┛", "┗", "┃", "╔", "═", "╗", "╝", "╚", "║", " ", "╣", "╦", "╩", "\n", "╱", "╲", "▩"};
    void draw( uint8_t longH[3], uint8_t segH[3], uint8_t longB[3], uint8_t segB[3], bool isRobot1);
    void printSignature();


};

#endif //INF1900_6674_DRAWING_H
