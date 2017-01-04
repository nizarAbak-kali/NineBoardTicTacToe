//
// Created by nizar on 07/11/16.
//

#ifndef INC_9BOARDTICTACTOE_BOARD_H
#define INC_9BOARDTICTACTOE_BOARD_H

#include "structs.h"
#include "Cell.h"
#include "Coup.h"


class Board {

public:
    int length;
    Cell tab[TABLE_LENGTH][TABLE_LENGTH];
    // cell position courrante
    pair<int, int> cell_courrante;

    pair<int, int> cell_old;



    // fonction pour obtenir une valeur du tableau
    Cell get(int x, int y );
    // fonction pour changer la valeur d'un case
    void set(int xcell, int ycell, int x, int y, int val);
    // constructeurs
    Board();
    // destructeur
    ~Board();
    // affiche le tablrzu
    void print();

    // save l'état de la board
    void save();
    // load un board
    void load();


    void joue(Coup &a) {
        cout << "COUP JOUE" << endl;
        pair_cp(&a.old_cell, &cell_courrante);


        this->set(this->cell_courrante.first, this->cell_courrante.second,
                  a.position_cell.first, a.position_cell.second, a.qui);

        pair_cp(&cell_courrante, &a.position_cell);


    }

    void dejoue(Coup &a) {
        cout << "COUP DEJOUE" << endl;


        pair_cp(&cell_courrante, &a.old_cell);

        a.print();
        this->set(this->cell_courrante.first, this->cell_courrante.second,
                  a.position_cell.first, a.position_cell.second, COUP_VIDE);


        // pair_cp(&cell_old,&a.old_cell);
    }

    void pair_cp(pair<int, int> *a, pair<int, int> *b) {
        a->first = b->first;
        a->second = b->second;
    }



    string toString();
};


#endif //INC_9BOARDTICTACTOE_BOARD_H
