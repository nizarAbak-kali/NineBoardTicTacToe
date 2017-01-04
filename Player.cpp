//
// Created by nizar on 07/11/16.
//

#include "includes/Player.h"

void Player::joue(Board &board, int xc, int yc) {
    Coup nouveau(this->pieces, pair<int, int>(xc, yc));
    board.joue(nouveau);

}

Player::Player(string nom, bool tour, int pieces) {
    this->nom = nom;

}
