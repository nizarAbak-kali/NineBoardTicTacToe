//
// Created by nizar on 07/11/16.
//

#include "includes/Board.h"

Board::Board() {
    this->length = TABLE_LENGTH;

    this->cell_courrante.first = 1;
    this->cell_courrante.second = 1;
    this->cell_old.first = cell_courrante.first;
    this->cell_old.second = cell_courrante.second;
}

Board::~Board() {
    //free(this->tab);
}

void Board::print() {
    cout<< "the board :"<<endl;
    string s ;

    for (int etage = 0; etage < length; etage++) {
        for (int y = 0; y < length; y++) {
            for (int cell = 0; cell < length; ++cell) {
                cout << this->tab[etage][cell].getLine(y);
                cout << "\t";
            }

            cout << "\n";
        }
        cout << "\n";
    }

}


Cell Board::get(int x, int y) {
    return tab[x][y];
}

void Board::set(int xcell, int ycell, int x, int y, int val) {
    tab[ycell][xcell].set(x, y, val);
}


string Board::toString() {
    string s = "Cellule courrante ";
    s += to_string(cell_courrante.first) + "  " + to_string(cell_courrante.second) + "\n";
    return s;
}



void Board::save() {
    ofstream myfile;
    myfile.open("/home/nizar/test/Board.txt");
    myfile << this->toString();
    myfile.close();
}
