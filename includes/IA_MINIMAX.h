//
// Created by nizar on 05/01/17.
//

#ifndef INC_9BOARDTICTACTOE_IA_MINIMAX_H
#define INC_9BOARDTICTACTOE_IA_MINIMAX_H

#include "structs.h"
#include "Board.h"
#include "Player.h"

class IA_MINIMAX : public Player {

public:
    Board b;
    int profondeur_max;

    IA_MINIMAX(string nom, bool tour, int pieces, Board &b, int prof) : Player(nom, tour, pieces) {
        this->nom = nom;
        this->pieces = pieces;
        this->b = b;
        this->profondeur_max = prof;
        srand((unsigned int) time(0));
    }

    int fini(int prof, int *res) {
        int code_gagnant = b.quiGagne();
        if (code_gagnant != COUP_VIDE) {
            *res = (code_gagnant == this->pieces) ? 1 : -1;
            return true;
        }
        if (this->b.plein()) {
            *res = COUP_VIDE;
            return true;
        }
        if (this->profondeur_max <= prof) {
            *res = (std::rand() % 3) - 1;
            return true;
        }
        return false;
    }


    int max(int profondeur) {

        int winner = 0;


        if (fini(profondeur, &winner)) {
            return winner;
        }

        int tmp, res = -2;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                Coup coup(this->pieces, pair<int, int>(i, j));
                if (!b.joue(coup)) {
                    continue;
                }

                tmp = min(profondeur + 1);

                b.dejoue(coup);

                if (tmp > res) res = tmp;

            }
        }
        return res;
    }

    int min(int profondeur) {

        int winner = 0;


        if (fini(profondeur, &winner)) {
            return winner;
        }

        int tmp, res = 2;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                int piece = this->pieces == COUP_O ? COUP_X : COUP_O;
                Coup coup(piece, pair<int, int>(i, j));
                if (!b.joue(coup)) {
                    continue;
                }

                tmp = max(profondeur + 1);

                b.dejoue(coup);

                if (tmp < res) res = tmp;

            }
        }
        return res;
    }

    void joue() {
        Coup coup;
        Coup final;
        int tmp, res = -2;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                coup.setQui(this->pieces);
                coup.set_position(i, j);

                if (!b.joue(coup)) {
                    continue;
                }

                tmp = min(0);

                b.dejoue(coup);

                if (tmp > res) {
                    res = tmp;
                    final.setQui(this->pieces);
                    final.set_position(i, j);
                }


            }
        }
        this->b.joue(final);
        return;
    }

};

#endif //INC_9BOARDTICTACTOE_IA_MINIMAX_H
