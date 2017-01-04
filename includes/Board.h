//
// Created by nizar on 07/11/16.
//

#ifndef INC_9BOARDTICTACTOE_BOARD_H
#define INC_9BOARDTICTACTOE_BOARD_H

#include "structs.h"
#include "Cell.h"


class Board {

public:
    int length;
    Cell tab[TABLE_LENGTH][TABLE_LENGTH];
    // cell position courrante
    int posx,posy;



    // fonction pour obtenir une valeur du tableau
    Cell get(int x, int y );
    // fonction pour changer la valeur d'un case
    void set(int x , int y, int val);
    // constructeurs
    Board();
    // destructeur
    ~Board();
    // affiche le tablrzu
    void print();

    // save l'état de la board
    void save();
    // load un board
    void load();

    string toString();
};


#endif //INC_9BOARDTICTACTOE_BOARD_H
