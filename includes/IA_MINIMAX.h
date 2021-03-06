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
    Board *b;
    int profondeur_max;

    IA_MINIMAX(string nom, bool tour, int pieces, Board &b, int prof) : Player(nom, tour, pieces) {
        this->nom = nom;
        this->pieces = pieces;
        this->b = &b;

        this->profondeur_max = prof;
        srand((unsigned int) time(0));
    }

    void print_cell(pair<int, int> i) {
        cout << i.first << " , " << i.second << endl;
    }


    int fini(int prof, int *res) {
        int code_gagnant = b->quiGagne();

        if (code_gagnant != COUP_VIDE) {
            if (DEBUG) { cout << "IA FINI GAGNANT " << code_gagnant << endl; }
            *res = (code_gagnant == this->pieces) ? 1 : -1;
            return true;
        }
        if (this->b->plein()) {
            if (DEBUG) { cout << "IA FINI PLEIN " << prof << endl; }
            *res = COUP_VIDE;
            return true;
        }
        if (this->profondeur_max <= prof) {
            if (DEBUG) { cout << "IA FINI PROF " << prof << endl; }
            *res = (std::rand() % 3) - 1;
            return true;
        }
        return false;
    }


    int max(int profondeur) {
        if (DEBUG) { cout << "IA Max  profondeur " << profondeur << endl; }

        int winner = 0;


        if (fini(profondeur, &winner)) {
            return winner;
        }

        int tmp, res = -2;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                Coup coup(this->pieces, pair<int, int>(i, j));
                if (!b->joue(coup)) {
                    if (DEBUG) { cout << "IA Max ON NE PAS JOUER CE COUP " << coup.toString() << endl; }
                    continue;
                }

                tmp = min(profondeur + 1);

                b->dejoue(coup);

                if (tmp > res) res = tmp;

            }
        }
        return res;
    }

    int min(int profondeur) {
        if (DEBUG) { cout << "IA Min: profondeur->" << profondeur << endl; }

        int winner = 0;


        if (fini(profondeur, &winner)) {
            if (DEBUG) { cout << "IA Min FINI " << endl; }
            return winner;
        }

        int tmp, res = 2;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                int piece = this->pieces == COUP_O ? COUP_X : COUP_O;
                Coup coup(piece, pair<int, int>(i, j));
                if (!b->joue(coup)) {
                    if (DEBUG) { cout << "IA Min ON NE PAS JOUER CE COUP " << coup.toString() << endl; }
                    continue;
                }

                tmp = max(profondeur + 1);

                b->dejoue(coup);

                if (tmp < res) res = tmp;

            }
        }
        return res;
    }

    void joue() {
        Coup coup;
        Coup final;
        int tmp, res = -2;
        cout << "CELLULE COURRANTE ";
        print_cell(b->cell_courrante);
        if (DEBUG) { cout << "IA" << this->nom << "JOUE : " << endl; }
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                coup.setQui(this->pieces);
                coup.set_position(i, j);

                if (!b->joue(coup)) {
                    continue;
                }

                tmp = min(0);

                b->dejoue(coup);

                if (tmp > res) {
                    res = tmp;
                    final.setQui(this->pieces);
                    final.set_position(i, j);
                }


            }
        }
        this->b->joue(final);
        cout << "CELLULE SUIVANTE ";
        print_cell(b->cell_courrante);
        return;
    }

};

#endif //INC_9BOARDTICTACTOE_IA_MINIMAX_H
