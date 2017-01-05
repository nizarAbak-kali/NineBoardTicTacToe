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

    const pair<int, int> &getPosition_cell() const;

    int getQui() const;

    int qui;

    Coup(int qui, pair<int, int> pos_cell);

    Coup() {}

    void set_position(int first, int second) {
        this->position_cell.first = first;
        this->position_cell.second = second;
    }



    void print() {
        // cout << "old coup :" << old_cell.first << "  " << old_cell.second;
    }
    string toString();

    void setQui(int qui);

};


#endif //INC_9BOARDTICTACTOE_COUP_H
