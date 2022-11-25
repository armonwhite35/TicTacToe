/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    int numPlayers;
    int row;
    int col;
    bool checkWin;
    bool checkBoard;
    srand(time(0));


    TicTacToe game;
    checkWin = game.checkForWin();
    checkBoard = game.isBoardFull();
    game.initializeBoard();

    cout << "One-player or Two-player (1 or 2):";
    cin >> numPlayers;

    while(checkWin == false || checkBoard == true)
    {
        game.printBoard();
        if (numPlayers == 1) {
            int currPlayer = game.getCurrentPlayerNumber();

            if (currPlayer == 2)
            {
                cout << "Player " << currPlayer << ":" << endl;
                game.placeMark((rand() % 2), (rand() % 2) );
            }

            else
                {
                    cout << "Player " << currPlayer << ":" << endl;
                    cout << "Enter row and Column:";
                    cin >> row >> col;

                    if ((row < 1 || row > 3) || (col < 1 || col > 3)) //if input is out of bounds
                    {
                        cout << "Out of Bounds." << endl;
                        cout << "Player " << currPlayer << ": " << endl;
                        cout << "Enter row and Column:";
                        cin >> row >> col;
                    }

                    game.placeMark((row - 1), (col - 1) ); //makes argument 0-2 instead of 1-3
                }


            if (game.checkForWin() == true)
            {
                break;
            }
            game.changePlayer();

        }

        if (numPlayers == 2)
        {
            int currPlayer = game.getCurrentPlayerNumber();
            cout << "Player " << currPlayer << ":" << endl;
            cout << "Enter row and Column:";
            cin >> row >> col;

            if ((row < 1 || row > 3) || (col < 1 || col > 3)) //if input is out of bounds
            {
                cout << "Out of Bounds." << endl;
                cout << "Player " << currPlayer << ": " << endl;
                cout << "Enter row and Column:";
                cin >> row >> col;
            }

            game.placeMark((row - 1), (col - 1) ); //makes argument 0-2 instead of 1-3

            if (game.checkForWin() == true)
            {
                break;
            }
            game.changePlayer();
        }
    }
    game.printBoard();

    if(game.checkForWin() == true)
    {
        cout << "Player " << game.getCurrentPlayerNumber() << " wins!" << endl;
    }

    else
        {
            cout << "It's a tie!" << endl;
        }



    return 0;
}