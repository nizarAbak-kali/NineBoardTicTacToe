//
// Created by nizar on 07/11/16.
//

#ifndef INC_9BOARDTICTACTOE_STRUCTS_H
#define INC_9BOARDTICTACTOE_STRUCTS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

#define TABLE_LENGTH 3
#define NUM_CELL 9
#define COUP_VIDE 0
#define COUP_X  1
#define COUP_O  2
using namespace std;

static inline int lc2p(int l, int c){ return l * NUM_CELL + c; }

static inline char code(int val){
    if (val == COUP_VIDE)
        return '_';
    if (val == COUP_X)
        return 'X';
     if (val == COUP_O)
        return 'O';

}





#endif //INC_9BOARDTICTACTOE_STRUCTS_H
