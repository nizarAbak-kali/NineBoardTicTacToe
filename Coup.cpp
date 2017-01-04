//
// Created by nizar on 16/11/16.
//

#include "includes/Coup.h"

Coup::Coup(int qui, pair<int, int> pos) {
    this->qui = qui;
    this->position = pos;
}

void Coup::print() {
    printf("[%d][%d]->%d",this->position.first, position.second, this->qui);
}

string Coup::toString() {
    string s = "["+to_string(this->position.first)+"]["+to_string(this->position.first)+"]->"+to_string(this->qui);
    return s;
}
