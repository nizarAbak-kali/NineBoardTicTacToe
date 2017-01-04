//
// Created by nizar on 07/11/16.
//

#include "includes/Board.h"

Board::Board() {
    this->length = TABLE_LENGTH;

}

Board::~Board() {
    free(this->tab);
}

void Board::print() {
    cout<< "the board :"<<endl;
    string s ;
    for (int l = 0; l < length; l++) {
        for (int j = 0; j < length; j++) {
            cout << l << " " << j << " : " <<endl;
            this->tab[l][j].print() ;

        }

    }

}


Cell Board::get(int x, int y) {
    return tab[x][y];
}

void Board::set(int x, int y, int val) {
    tab[x][y].set(x,y,val);
}


string Board::toString() {
    string s = "";

    for (int l = 0; l < length; l++) {
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                for (int i = 0; k < length; k++) {
                    s += this->tab[l][k].get(j, i) + " ";
                }
                s += "\t";

            }
            s = s + "\n";
        }
    }
    return s;
}



void Board::save() {
    ofstream myfile;
    myfile.open("/home/nizar/test/Board.txt");
    myfile << this->toString();
    myfile.close();
}
