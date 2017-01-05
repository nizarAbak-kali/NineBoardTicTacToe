#include <iostream>
#include "includes/Board.h"
#include "includes/IA_MINIMAX.h"



int main() {
    std::cout << "Hello, World !" << std::endl;
    Board b;
    IA_MINIMAX ia1("minimaxi", true, COUP_X, b, 4);
    IA_MINIMAX ia2("minimaximax", false, COUP_O, b, 4);


    while (b.quiGagne() == COUP_VIDE) {
        cout << "Vainqueur !! ->" << b.code(b.quiGagne()) << endl;
        cout << "JOUEUR 1 joue !!" << endl;
        ia1.joue();
        b.print();
        cout << b.toString() << endl;
        cout << "JOUEUR 2 joue !!" << endl;
        ia2.joue();
        b.print();
        cout << b.toString() << endl;
    }

    return 0;
}