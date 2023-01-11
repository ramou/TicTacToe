#include "TicTacToe.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    

    //Shh... this is currentPlayer!
    // ...or wherever currentpPlayer is
    //*(((char*)(&game1)) + 12) = 'O';

    string s;
    //Get players
    cout << "What is the name of player 1 ?" << endl;
    cin >> s;
    Player p1(s);

    cout << "What is the name of player 2 ?" << endl;
    cin >> s;
    Player p2(s);


    TicTacToe game1(p1, p2);
    game1.play();


    /*
    TicTacToe game2;
    game2.play();

    

    game1.printboard();
    */

    return 0;
}