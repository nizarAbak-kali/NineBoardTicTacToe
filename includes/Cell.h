//
// Created by nizar on 16/11/16.
//

#ifndef INC_9BOARDTICTACTOE_CELL_H
#define INC_9BOARDTICTACTOE_CELL_H

#include "structs.h"
#include "Coup.h"

class Cell {
public:
    int** tab;
    Cell(){
        tab = new int* [TABLE_LENGTH];
        for (int i = 0 ; i < TABLE_LENGTH; i++)
            tab[i] = new int[TABLE_LENGTH];

        for(int i = 0; i< TABLE_LENGTH; i++){
            for (int j ;j < TABLE_LENGTH; j++){
                tab[i][j] = COUP_VIDE;
            }
        }
    };

    void set(int x, int y, int val){
        this->tab[x][y] = val;
    }


    int get(int x, int y){
        return this->tab[x][y] ;
    }

    string code(int val) {
        if (val == COUP_VIDE)
            return "_";
        if (val == COUP_X)
            return "X";
        if (val == COUP_O)
            return "O";

    }

    string getLine(int y) {
        string n = "";
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            n += code(get(i, y)) + " ";
        }
        return n;
    }


    void print(){
        for(int  i = 0;i < TABLE_LENGTH; i++){
            for(int j = 0 ;j < TABLE_LENGTH;j++){
                cout << to_string(tab[j][i]) << " ";
            }
            cout << endl;
        }
    }


    void Free_Tab(){
        for (int i=0; i < TABLE_LENGTH; i++)
            delete[] tab[i];
        delete[] tab;
    }

    int quiGagneCell() {

        for (int i = 0; i < TABLE_LENGTH; ++i) {
            if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2] && tab[i][0] != COUP_VIDE) {
                if (DEBUG) cout << " GAGNÉ  ligne!!!" << endl;
                return tab[i][0];
            }
        }
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i] && tab[0][i] != COUP_VIDE) {
                if (DEBUG) cout << " GAGNÉ  colonne!!!" << endl;
                return tab[0][i];
            }
        }

        if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] != COUP_VIDE) {
            if (DEBUG)cout << " GAGNÉ  diagonale!!!" << endl;
            return tab[0][0];
        }

        if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] != COUP_VIDE && tab[1][1] != COUP_VIDE &&
            tab[2][0] != COUP_VIDE) {
            if (DEBUG) cout << " GAGNÉ  oblique!!!" << endl;
            return tab[0][2];
        }
        return COUP_VIDE;
    }

    bool vide() {
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                if (tab[i][j] == COUP_VIDE) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<Coup> coupPossibleCell(int piece) {
        vector<Coup> v;
        Coup a;
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            for (int j = 0; j < TABLE_LENGTH; ++j) {
                if (tab[i][j] == COUP_VIDE) {
                    a.setQui(piece);
                    a.set_position(i, j);
                    v.push_back(a);
                }
            }
        }
        return v;
    }
};


#endif //INC_9BOARDTICTACTOE_CELL_H
