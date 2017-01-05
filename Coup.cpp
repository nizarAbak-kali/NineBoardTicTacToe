//
// Created by nizar on 16/11/16.
//

#include "includes/Coup.h"

Coup::Coup(int qui, pair<int, int> pos_c) {
    this->qui = qui;
    this->position_cell.first = pos_c.first;
    this->position_cell.second = pos_c.second;

}

const pair<int, int> &Coup::getPosition_cell() const {
    return position_cell;
}

void Coup::setQui(int qui) {
    Coup::qui = qui;
}

int Coup::getQui() const {
    return qui;
}



/*
string Coup::toString() {
    string s = "["+to_string(this->position.first)+"]["+to_string(this->position.first)+"]->"+to_string(this->qui);
    return s;
}
*/