//
// Created by nizar on 07/11/16.
//
#ifndef INC_9BOARDTICTACTOE_PLAYER_H
#define INC_9BOARDTICTACTOE_PLAYER_H

#include "structs.h"
#include "Board.h"
#include "Coup.h"

class Player {

public:
    string nom;
    bool tour;
    int pieces;
    vector<Coup> liste_coups;

    Player(string nom,bool tour,int pieces);

    void joue(Board &board, int x, int y, int val);
};


#endif //INC_9BOARDTICTACTOE_PLAYER_H
