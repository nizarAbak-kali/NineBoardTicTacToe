//
// Created by nizar on 09/01/17.
//

#ifndef INC_9BOARDTICTACTOE_IA_MC_H
#define INC_9BOARDTICTACTOE_IA_MC_H


#include "Player.h"

class IA_MC : public Player {

public:
    Board *b;
    int profondeur_max;
    int maxCoup;
    int nplayout;

    IA_MC(string nom, bool tour, int pieces, Board &b, int MaxCoup, int playout) : Player(nom, tour, pieces) {
        this->nom = nom;
        this->pieces = pieces;
        this->b = &b;

        this->maxCoup = MaxCoup;
        this->nplayout = playout;
        srand((unsigned int) time(0));
    }

    void print_cell(pair<int, int> i) {
        cout << i.first << " , " << i.second << endl;
    }


    int fini(int *res, Board b) {
        int code_gagnant = b.quiGagne();

        if (code_gagnant != COUP_VIDE) {
            if (DEBUG) { cout << "IA FINI GAGNANT " << code_gagnant << endl; }
            *res = (code_gagnant == this->pieces) ? 1 : -1;
            return true;
        }
        if (this->b->plein()) {
            if (DEBUG) { cout << "IA FINI PLEIN " << playout() << endl; }
            *res = COUP_VIDE;
            return true;
        }

        return false;
    }


    int playout() {
        int t;
        int nel;
        vector<Coup> liste;
        Board copie = *this->b;

        while (!this->fini(&t, copie)) {

            liste = copie.liste_coupPossible(this->pieces);
            nel = (int) liste.size();


            Coup coupAlea = liste[rand() % nel];
            copie.joue(coupAlea);
        }
        return t;
    }

    void joue() {
        vector<Coup> liste(maxCoup);
        int nel;
        int score[maxCoup];
        int i, imax;

        liste = this->b->liste_coupPossible(this->pieces);
        nel = (int) liste.size();

        for (int j = 0; j < nel; ++j) {
            score[j] = 0;
        }

        // jouer des playouts et noter le résultat pour le premier coup

        for (int i = 0; i < nplayout; i++) {
            Coup coupAlea = liste[i % nel];
            b->joue(coupAlea);
            score[i % nel] += playout();
            b->dejoue(coupAlea);
        }
        // choisir celui avec le meilleur score
        for (imax = 0, i = 1; i < nel; i++)
            if ((this->pieces == COUP_X && score[i] > score[imax]) ||
                (this->pieces == COUP_O && score[i] < score[imax]))
                imax = i;

        b->joue(liste[imax]);

    }


};

#endif //INC_9BOARDTICTACTOE_IA_MC_H
