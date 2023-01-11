#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::printboard() {
    for (int y = 0; y < 3; y++) { // A line
        cout << "\t";
        for (int x = 0; x < 3; x++) { // An entry
            cout << board[x + y * 3];
        }
        cout << endl;
    }
}

TicTacToe::TicTacToe(Player p1, Player p2) : first(p1), second(p2) {
    for (int i = 0; i < 9; i++) board[i] = SPACE;
}


void TicTacToe::play() {
    //Do many turns
    do {
        //Draw the board
        printboard();
        cout << "It is " << currentPlayer->getName() <<"'s turn. Please place an " << getCurrentPlayerSymbol() << " by choosing 0 to 8." << endl;

        //Get a play
        int play;
        cin >> play;

        //Confirm the play is on the board
        if (play < 0 || play >8) {
            cout << "Invalid range, please pick a position between 0 and 8, inclusive." << endl;
            continue;
        }

        if (board[play] != SPACE) {
            cout << "Position " << play << " is already occupied!" << endl;
            continue;
        }
        board[play] = getCurrentPlayerSymbol();

        for (int y = 0; y < 3; y++) { // Checking Rows
            won |= (board[0 + y * 3] != SPACE) && (board[0 + y * 3] == board[1 + y * 3]) && (board[1 + y * 3] == board[2 + y * 3]);
        }
        for (int x = 0; x < 3; x++) { // Checking Columns
            won |= (board[x + 0 * 3] != SPACE) && (board[x + 0 * 3] == board[x + 1 * 3]) && (board[x + 1 * 3] == board[x + 2 * 3]);
        }
        won |= (board[4] != SPACE) && (board[0] == board[4]) && (board[4] == board[8]);
        won |= (board[4] != SPACE) && (board[6] == board[4]) && (board[4] == board[2]);

        moreMoves = false;
        for (int i = 0; i < 9; i++) {
            moreMoves |= (board[i] == SPACE);
        }

        if (!won) {
            if (currentPlayer == &first) currentPlayer = &second;
            else currentPlayer = &first;
        }
    } while (!won && moreMoves);

    //Draw the final board
    printboard();

    //Declare winner, if someone won
    if (won) {
        cout << currentPlayer->getName() << " won!" << endl;
    } // Declare Tie if nobody won
    else if (!moreMoves) cout << "Tie Game!" << endl;

}

char TicTacToe::getCurrentPlayerSymbol(){
    return (currentPlayer == &first) ? X : O;
}
