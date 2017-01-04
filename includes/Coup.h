//
// Created by nizar on 16/11/16.
//

#ifndef INC_9BOARDTICTACTOE_COUP_H
#define INC_9BOARDTICTACTOE_COUP_H

#include "structs.h"

class Coup {
public:
    pair<int,int> position;
    int qui;

    Coup(int qui, pair<int,int> pos);
    void print();
    string toString();

};


#endif //INC_9BOARDTICTACTOE_COUP_H
