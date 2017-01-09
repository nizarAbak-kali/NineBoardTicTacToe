//
// Created by nizar on 09/01/17.
//

#ifndef INC_9BOARDTICTACTOE_IA_ALPHABETA_H
#define INC_9BOARDTICTACTOE_IA_ALPHABETA_H

#include "Player.h"

class IA_AlphaBeta : public Player {

public:
    Board *b;
    int profondeur_max_AlphaBeta;

    IA_AlphaBeta(string nom, bool tour, int pieces, Board &b, int prof) : Player(nom, tour, pieces) {
        this->nom = nom;
        this->pieces = pieces;
        this->b = &b;

        this->profondeur_max_AlphaBeta = prof;
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
        if (this->profondeur_max_AlphaBeta <= prof) {
            if (DEBUG) { cout << "IA FINI PROF " << prof << endl; }
            *res = (std::rand() % 3) - 1;
            return true;
        }
        return false;
    }


    int min_AlphaBeta(int profondeur, int alpha, int beta) {
        if (DEBUG) { cout << "IA min_AlphaBeta: profondeur->" << profondeur << endl; }

        int winner = 0;


        if (fini(profondeur, &winner)) {
            if (DEBUG) { cout << "IA min_AlphaBeta FINI " << endl; }
            return winner;
        }

        int tmp;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                int piece = this->pieces == COUP_O ? COUP_X : COUP_O;
                Coup coup(piece, pair<int, int>(i, j));
                if (!b->joue(coup)) {
                    if (DEBUG) { cout << "IA min_AlphaBeta ON NE PAS JOUER CE COUP " << coup.toString() << endl; }
                    continue;
                }

                tmp = max_AlphaBeta(profondeur + 1, alpha, beta);

                b->dejoue(coup);

                if (tmp < beta)
                    beta = tmp;
                if (beta <= alpha)
                    break;

            }
        }
        return beta;
    }

    int max_AlphaBeta(int profondeur, int alpha, int beta) {
        if (DEBUG) { cout << "IA max_AlphaBeta  profondeur " << profondeur << endl; }

        int winner = 0;


        if (fini(profondeur, &winner)) {
            return winner;
        }

        int tmp;

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                Coup coup(this->pieces, pair<int, int>(i, j));
                if (!b->joue(coup)) {
                    if (DEBUG) { cout << "IA max_AlphaBeta ON NE PAS JOUER CE COUP " << coup.toString() << endl; }
                    continue;
                }

                tmp = min_AlphaBeta(profondeur + 1, alpha, beta);

                b->dejoue(coup);

                if (tmp > alpha)
                    alpha = tmp;
                if (alpha >= beta)
                    break;

            }
        }
        return alpha;
    }

    void joue() {
        Coup coup;
        Coup final;
        int tmp = -2;

        int alpha = -2;
        int beta = 2;
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

                tmp = min_AlphaBeta(0, alpha, beta);

                b->dejoue(coup);

                if (tmp > alpha) {
                    alpha = tmp;
                    final.setQui(this->pieces);
                    final.set_position(i, j);
                }
                if (alpha >= beta)
                    break;

            }
        }
        this->b->joue(final);
        cout << "CELLULE SUIVANTE ";
        print_cell(b->cell_courrante);
        return;
    }

};

#endif //INC_9BOARDTICTACTOE_IA_ALPHABETA_H
