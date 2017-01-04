//
// Created by nizar on 16/11/16.
//

#include "includes/Coup.h"

Coup::Coup(int qui, pair<int, int> pos_c) {
    this->qui = qui;
    this->position_cell.first = pos_c.first;
    this->position_cell.second = pos_c.second;

}



/*
string Coup::toString() {
    string s = "["+to_string(this->position.first)+"]["+to_string(this->position.first)+"]->"+to_string(this->qui);
    return s;
}
*/