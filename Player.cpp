//
// Created by nizar on 07/11/16.
//

#include "includes/Player.h"
#include "includes/Board.h"

void Player::joue(Board& board,int x, int y, int val) {
    board.set(x,y,val);
}

Player::Player(string nom, bool tour, int pieces) {
    this->nom = nom;

}
