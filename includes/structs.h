//
// Created by nizar on 07/11/16.
//

#ifndef INC_9BOARDTICTACTOE_STRUCTS_H
#define INC_9BOARDTICTACTOE_STRUCTS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define TABLE_LENGTH 3
#define NUM_CELL 9
#define COUP_VIDE 0
#define COUP_X  1
#define COUP_O  2
#define DEBUG false
using namespace std;

static inline int lc2p(int l, int c){ return l * NUM_CELL + c; }




#endif //INC_9BOARDTICTACTOE_STRUCTS_H
