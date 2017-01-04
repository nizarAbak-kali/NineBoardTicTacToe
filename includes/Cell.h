//
// Created by nizar on 16/11/16.
//

#ifndef INC_9BOARDTICTACTOE_CELL_H
#define INC_9BOARDTICTACTOE_CELL_H

#include "structs.h"

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

    string getLine(int y) {
        string n = "";
        for (int i = 0; i < TABLE_LENGTH; ++i) {
            n += to_string(get(i, y)) + " ";
        }
        return n;
    }


    void print(){
        for(int  i = 0;i < TABLE_LENGTH; i++){
            for(int j = 0 ;j < TABLE_LENGTH;j++){
                cout << to_string(tab[i][j]) << " ";
            }
            cout << endl;
        }
    }


    void Free_Tab(){
        for (int i=0; i < TABLE_LENGTH; i++)
            delete[] tab[i];
        delete[] tab;
    }

};


#endif //INC_9BOARDTICTACTOE_CELL_H
