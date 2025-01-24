
#include "Drawing.h"




Draw::Draw(){}

uint8_t Draw::drawBox2(int i, int j, uint8_t longueurHaut[3], uint8_t segmentHaut[3], uint8_t longueurBas[3], uint8_t segmentBas[3], bool estRobot1) {

    uint8_t startPositionX = BOX_1_START_POSITION_X;
    uint8_t startPositionY = BOX_1_START_POSITION_Y;


    if((i == 11) && (j == 45)){
        return CHAR_RIGHT_DOUBLE;
    }
    else if((i == 11) && ( (j == 44) || (j == 43) || (j == 42) ||  (j == 41) ||  (j == 40) ||  (j == 39) ||  (j == 38))){
        return CHAR_HORIZONTAL_TRIPLE;
    }else if((i == 20) && ( (j == 58))){
        return CHAR_HORIZONTAL_TRIPLE;
    }

        if (estRobot1) {
        if ((i == startPositionY + 6) && (j == startPositionX + 12)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 6) && (j == startPositionX + 13)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 6) && (j == startPositionX + 11)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 6) && (j == startPositionX + 14)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 7) && (j == startPositionX + 11)) {
            return CHAR_SLASH;
        } else if ((i == startPositionY + 7) && (j == startPositionX + 14)) {
            return CHAR_BACKSLASH;
        } else if ((i == startPositionY + 8) && (j == startPositionX + 15)) {
            return CHAR_VERTICAL;
        } else if ((i == startPositionY + 8) && (j == startPositionX + 10)) {
            return CHAR_VERTICAL;
        } else if ((i == startPositionY + 9) && (j == startPositionX + 10)) {
            return CHAR_SQUARE;
        } else if ((i == startPositionY +  9) && (j == startPositionX + 15)) {
            return CHAR_SQUARE;
        } else if ((i == startPositionY + 10) && (j == startPositionX + 10)) {
            return CHAR_BACKSLASH;
        } else if ((i == startPositionY + 10) && (j == startPositionX + 15)) {
            return CHAR_SLASH;
        } else if ((i == startPositionY + 11) && (j == startPositionX + 11)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 11) && (j == startPositionX + 12)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 11) && (j == startPositionX + 13)) {
            return CHAR_HORIZONTAL;
        } else if ((i == startPositionY + 11) && (j == startPositionX + 14)) {
            return CHAR_HORIZONTAL;
        }

    }

    
    if((i == startPositionY) && (j == startPositionX)){
        return CHAR_TOP_LEFT_DOUBLE;
    }else if((i == startPositionY) && (j == BOX_1_END_POSITION_Y)) {
        return CHAR_TOP_RIGHT_DOUBLE;
    }else if((i == BOX_2_END_POSITION_X) && (j == startPositionX)) {
        return CHAR_BOTTOM_LEFT_DOUBLE;
    }else if((i == BOX_2_END_POSITION_X) && (j == BOX_1_END_POSITION_Y)) {
        return CHAR_BOTTOM_RIGHT_DOUBLE;
    }
    
    
    


    else if((i == startPositionY) && (j > startPositionX) && (j < BOX_1_END_POSITION_Y)){
        return CHAR_HORIZONTAL_DOUBLE;
    }else if((i >= startPositionY + 1) && (j == startPositionX) && (i < BOX_1_END_POSITION_X)){
        return CHAR_VERTICAL_DOUBLE;
    }else if((i >= startPositionY + 1) && (j == BOX_1_END_POSITION_Y)  && (i < BOX_1_END_POSITION_X) &&( (i < 9) || (i > 12))){
        return CHAR_VERTICAL_DOUBLE;
    } else if((i == 20) && (j < 30) && (j > startPositionX)){
        return CHAR_HORIZONTAL_DOUBLE;
    } 

    startPositionX = BOX_2_START_POSITION_X;
    startPositionY = BOX_2_START_POSITION_Y;


    if((i == startPositionY) && (j == startPositionX)){
        return CHAR_TOP_LEFT_TRIPLE;
    }
    else if((i == 20) && (j == 98)){
        return CHAR_BOTTOM_RIGHT_TRIPLE;
    }
    else if((i == startPositionY + 1) && (j < BOX_2_END_POSITION_Y) && (   (j == (longueurHaut[0] + startPositionX)) || ((j == (longueurHaut[1] + startPositionX))  && segmentHaut[1] != 0) || (j == (longueurHaut[0] + startPositionX)) || ((j == (longueurHaut[2] + startPositionX))  && segmentHaut[2] != 0)))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 2) && (segmentHaut[0] >= 4) && ((j == (longueurHaut[0] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 2) && (segmentHaut[1] >= 4) && ((j == (longueurHaut[1] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 2) && (segmentHaut[2] >= 4) && ((j == (longueurHaut[2] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == startPositionY + 3) && (segmentHaut[0] >= 6) && ((j == (longueurHaut[0] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 3) && (segmentHaut[1] >= 6) && ((j == (longueurHaut[1] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 3) && (segmentHaut[2] >= 6) && ((j == (longueurHaut[2] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == startPositionY + 4) && (segmentHaut[0] >= 8) && ((j == (longueurHaut[0] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 4) && (segmentHaut[1] >= 8) && ((j == (longueurHaut[1] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 4) && (segmentHaut[2] >= 8) && ((j == (longueurHaut[2] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == startPositionY + 5) && (segmentHaut[0] >= 8) && ((j == (longueurHaut[0] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 5) && (segmentHaut[1] >= 8) && ((j == (longueurHaut[1] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == startPositionY + 5) && (segmentHaut[2] >= 8) && ((j == (longueurHaut[2] + startPositionX))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == 20) && (j == (BOX_2_END_POSITION_Y - longueurBas[0]))){
        return CHAR_BOTTOM_DOUBLE;
    }else if((i == 20) && (j == (BOX_2_END_POSITION_Y - longueurBas[1])) && (segmentBas[1] != 0)){
        return CHAR_BOTTOM_DOUBLE;
    }else if((i == 20) && (j == (BOX_2_END_POSITION_Y - longueurBas[2])) && (segmentBas[2] != 0)){
        return CHAR_BOTTOM_DOUBLE;
    }else if((i == 20) && (j == (BOX_2_END_POSITION_Y - longueurBas[1])) && (segmentBas[1] == 0)){
        return CHAR_HORIZONTAL_TRIPLE;
    }else if((i == 20) && (j == (BOX_2_END_POSITION_Y - longueurBas[2])) && (segmentBas[2] == 0)){
        return CHAR_HORIZONTAL_TRIPLE;
    }


    else if((i == 19) && ((j == (BOX_2_END_POSITION_Y - longueurBas[0]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 19) && ((j == (BOX_2_END_POSITION_Y - longueurBas[1])) && (segmentBas[1] != 0)))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 19) && ((j == (BOX_2_END_POSITION_Y - longueurBas[2])) && (segmentBas[2] != 0)))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 2) && (segmentBas[0] >= 4) && ((j == (BOX_2_END_POSITION_Y - longueurBas[0]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 2) && (segmentBas[1] >= 4) && ((j == (BOX_2_END_POSITION_Y - longueurBas[1]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 2) && (segmentBas[2] >= 4) && ((j == (BOX_2_END_POSITION_Y - longueurBas[2]))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == 20 - 3) && (segmentBas[0] >= 6) && ((j == (BOX_2_END_POSITION_Y - longueurBas[0]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 3) && (segmentBas[1] >= 6) && ((j == (BOX_2_END_POSITION_Y - longueurBas[1]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 3) && (segmentBas[2] >= 6) && ((j == (BOX_2_END_POSITION_Y - longueurBas[2]))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == 20 - 4) && (segmentBas[0] >= 8) && ((j == (BOX_2_END_POSITION_Y - longueurBas[0]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 4) && (segmentBas[1] >= 8) && ((j == (BOX_2_END_POSITION_Y - longueurBas[1]))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 4) && (segmentBas[2] >= 8) && ((j == (BOX_2_END_POSITION_Y - longueurBas[2]))))
        return CHAR_VERTICAL_TRIPLE;

    else if((i == 20 - 5) && (segmentBas[0] >= 8) && ((j == ((BOX_2_END_POSITION_Y - longueurBas[0])))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 5) && (segmentBas[1] >= 8) && ((j == ((BOX_2_END_POSITION_Y - longueurBas[1])))))
        return CHAR_VERTICAL_TRIPLE;
    else if((i == 20 - 5) && (segmentBas[2] >= 8) && ((j == ((BOX_2_END_POSITION_Y - longueurBas[2])))))
        return CHAR_VERTICAL_TRIPLE;


    else if((i == startPositionY) && (j > startPositionX) && (j != (longueurHaut[0] + startPositionX)) && (j < BOX_2_END_POSITION_Y) && (j != (longueurHaut[1] + startPositionX)) && (j != (longueurHaut[2] + startPositionX)))
        return CHAR_HORIZONTAL_TRIPLE;
    else if((i >= (startPositionY + 1)) && (j == startPositionX) && (i <= 19)) {
        return CHAR_VERTICAL_TRIPLE;
    }
    else if((i == startPositionY) && (j == BOX_2_END_POSITION_Y)){
        return CHAR_TOP_RIGHT_TRIPLE;
    }else if((i > startPositionY) && (j == BOX_2_END_POSITION_Y) && (i <= 19)){
        return CHAR_VERTICAL_TRIPLE;
    }else if((i == 20) && (j == startPositionX)){
        return CHAR_BOTTOM_LEFT_TRIPLE;
    
    }else if((i == 20) && (j > startPositionX) && (j != (longueurHaut[0] + startPositionX)) && (j < BOX_2_END_POSITION_Y))
        return CHAR_HORIZONTAL_TRIPLE;



    else if((i == startPositionY) && (j == (longueurHaut[0] + startPositionX))){
        return CHAR_TOP_DOUBLE;
    }

    else if((i == startPositionY) && (j == (longueurHaut[2] + startPositionX)) && (segmentHaut[2] != 0)){
        return CHAR_TOP_DOUBLE;
    }
    else if((i == startPositionY) && (j == (longueurHaut[1] + startPositionX)) && (segmentHaut[1] != 0)){
        return CHAR_TOP_DOUBLE;
    }
    else if((i == startPositionY) && (j == (longueurHaut[2] + startPositionX)) && (segmentHaut[2] == 0)){
        return CHAR_HORIZONTAL_TRIPLE;
    }
    else if((i == startPositionY) && (j == (longueurHaut[1] + startPositionX)) && (segmentHaut[1] == 0)){
        return CHAR_HORIZONTAL_TRIPLE;
    }



    else if ((i >= 1) && (i < 20) && (j < BORDER_END_POSITION_X) && (j > BORDER_START_POSITION_Y) && (i < BORDER_END_POSITION_Y)){
        return CHAR_BLANK;
    } else if ((i >= 1) && (i < BORDER_END_POSITION_Y) && (j == BORDER_END_POSITION_X)){
        return CHAR_VERTICAL;
    } else if ((i >= 1) && (i < BORDER_END_POSITION_Y) && (j == BORDER_START_POSITION_Y)){
        return CHAR_VERTICAL;
    }
    if (i == BORDER_START_POSITION_X && j == BORDER_START_POSITION_Y) {
        return CHAR_TOP_LEFT;
    }
    else if ((i == 0) && (j < BORDER_END_POSITION_X)) {
        return CHAR_HORIZONTAL;
    }else if ((i == 0) && (j == BORDER_END_POSITION_X)) {
        return CHAR_TOP_RIGHT;
    }

    else if ((i == BORDER_END_POSITION_Y) && (j < BORDER_END_POSITION_X) && (j > BORDER_START_POSITION_Y)) {
        return CHAR_HORIZONTAL;
    }else if ((i == BORDER_END_POSITION_Y) && (j == BORDER_END_POSITION_X)) {
        return CHAR_BOTTOM_RIGHT;
    } else if ((i == BORDER_END_POSITION_Y) && (j == BORDER_START_POSITION_Y)) {
        return CHAR_BOTTOM_LEFT;
    }

    else{
        return CHAR_BLANK;
    }




}

void Draw::printSignature(){
    Rs232 rs232 = Rs232::creerInstance();
    uint8_t signature[] = "Produit par: Mousquetaires";

    uint8_t mots_len = sizeof(signature);

    Memoire24CXXX memoire;
    memoire.ecriture(0x00, signature, mots_len); 

    uint8_t char_lu;
    for (uint8_t i = 0; i < mots_len; i++)
    {
        memoire.lecture(0x00 + i, &char_lu);
        rs232.transmission((char_lu));
    }
}


void Draw::draw( uint8_t longH[3], uint8_t segH[3], uint8_t longB[3], uint8_t segB[3], bool isRobot1){
    Rs232 rs232 = Rs232::creerInstance();
       for (int i = 0; i <= 26; i++)
   {
        for (int j = 0; j <= 101; j++)

        {
            Led led;
            led.allumerVert();
            _delay_ms(50);
            led.fermer();
            _delay_ms(50);
            rs232.transmissionChar(CHARACTERS[drawBox2(i, j, longH, segH, longB, segB, isRobot1)]);
        }
        rs232.transmissionChar(CHARACTERS[23]);
   }
   rs232.transmissionChar(CHARACTERS[23]);

   if(isRobot1){
    printSignature();
   }
   
}
