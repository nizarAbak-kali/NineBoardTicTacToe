#include <iostream>
#include "includes/Board.h"
#include "includes/IA_MINIMAX.h"
#include "includes/IA_AlphaBeta.h"
#include "includes/IA_MC.h"

void jeu() {
    Board b;
    // IA_MINIMAX ia1("maxichoco", false, COUP_X, b, 6);
    // IA_MINIMAX ia2("minimaximax", true, COUP_O, b, 6);
    IA_AlphaBeta ia1("alpha", false, COUP_X, b, 6);
    // IA_AlphaBeta ia2("omega", true, COUP_O, b, 6);
    IA_MC ia2("montecristo", true, COUP_O, b, 6, 5);
    int tour = 0;


    while (b.quiGagne() == COUP_VIDE) {

        cout << "Tour " << tour++ << " : de !! ->" << b.code(b.quiGagne()) << endl;
        cout << "JOUEUR 1 joue !!" << endl;
        ia1.joue();
        b.print();
        if (b.quiGagne() != COUP_VIDE) {
            cout << "Vainqueur !! ->" << b.code(b.quiGagne()) << endl;
            break;
        }
        cout << b.toString() << endl;
        cout << "JOUEUR 2 joue !!" << endl;
        ia2.joue();
        b.print();
        cout << b.toString() << endl;
    }
    cout << "Vainqueur !! ->" << b.code(b.quiGagne()) << endl;

}


void test() {
    Board b;
    IA_MINIMAX ia1("minimaxi", true, COUP_X, b, 5);
    IA_MINIMAX ia2("minimaximax", false, COUP_O, b, 5);

    cout << b.toString() << endl;
    b.print();
    ia1.joue();
    cout << b.toString() << endl;
    b.print();
    ia2.joue();
    cout << b.toString() << endl;
    b.print();

}

int main() {
    std::cout << "Hello, World !" << std::endl;

    jeu();
    //test();

    return 0;
}