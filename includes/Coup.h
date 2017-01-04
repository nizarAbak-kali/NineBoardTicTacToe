//
// Created by nizar on 16/11/16.
//

#ifndef INC_9BOARDTICTACTOE_COUP_H
#define INC_9BOARDTICTACTOE_COUP_H

#include "structs.h"

class Coup {
public:
    pair<int, int> position_cell;
    pair<int, int> old_cell;
    int qui;

    Coup(int qui, pair<int, int> pos_cell);

    void print() {
        cout << "old coup :" << old_cell.first << "  " << old_cell.second;
    }
    string toString();

};


#endif //INC_9BOARDTICTACTOE_COUP_H
