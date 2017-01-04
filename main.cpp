#include <iostream>
#include "includes/Board.h"




int main() {
    std::cout << "Hello, World !" << std::endl;
    Board b;

    b.print();
    cout << b.toString() << endl;
    Coup a(COUP_O, pair<int, int>(1, 2));
    b.joue(a);
    b.print();
    cout << b.toString() << endl;

    Coup a1(COUP_X, pair<int, int>(0, 0));
    b.joue(a1);
    b.print();
    cout << b.toString() << endl;

    Coup a2(COUP_O, pair<int, int>(2, 1));
    b.joue(a2);
    b.print();
    cout << b.toString() << endl;

    b.dejoue(a2);
    b.print();
    cout << b.toString() << endl;

    b.dejoue(a1);
    b.print();
    cout << b.toString() << endl;


    b.dejoue(a);
    b.print();
    cout << b.toString() << endl;




    return 0;
}