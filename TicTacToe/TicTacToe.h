#include "Player.h"
#pragma once
class TicTacToe
{
public:
    TicTacToe(Player p1, Player p2);
    void printboard();
    void play();

private:
    static const char X = 'X', O = 'O', SPACE = '.';

    char getCurrentPlayerSymbol();


    //Set up board like this:
    //{.,.,.,
    // .,.,.,
    // .,.,.}

    //00 01 02
    //03 04 05
    //06 07 08
    char board[9];

    Player first, second;
    Player *currentPlayer = &first;
    bool won = false, moreMoves = true;
};

