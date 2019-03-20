#include <iostream>
#include <string>
#include "Board.hpp"

using namespace std;

/*
To summarize, we are looking for:
1. Data model representing the current state of the game
2. Implementation of the function that will be called after each game turn in order to update the model and check if we have a winner
  a. Accepts the column into which the piece has been placed
  b. Accepts the type of piece placed
  c. Accepts the current board object (if necessary)
  d. Returns true if last move is the winner, false otherwise
3. Unit tests that validate the logic of the function
 
Things to focus on:
1. Elegant and fast implementation (hint: can use recursion)
2. Clean and easy to read code (use comments and meaningful variable names)
3. Good tests
 */

int main ()
{
    string input;
    cout << "Do you want to play a game of Connect 4 [y/n]" << endl;
    getline(cin, input);

    if (input.compare("y") != 0 && input.compare("yes") != 0)
    {
        return 0;
    }

    cout << "What size width board would you like to play?" << endl;

    int width;
    cin >> width;

    if (width < 4)
    {
        cout << "Width defaulted to 7";
        width = 7;
    }

    cout << "What size height board would you like to play?" << endl;

    int height;
    cin >> height;

    if (height < 4)
    {
        cout << "Height defaulted to 6";
        height = 6;
    }

start:
    Board* board = new Board(width, height);

    Player currPlayer;

    // Play loop
    while (true)
    {
        int column;

        currPlayer = PlayerA;
        cout << "Player A: What column do you want to play? [ 0 - " << width - 1 << " ]"<< endl;
        cin >> column;
        if (cin.fail())
        {
            column = -1;
            cin.clear();
            cin.ignore();
            cout << "Invalid input please use integers" << endl;
        }
        if (board->playPiece(PlayerA, column)) break;

        board->printBoard(cout);

        currPlayer = PlayerB;
        cout << "Player B: What column do you want to play? [ 0 - " << width - 1 << " ]"<< endl;
        cin >> column;
        if (cin.fail())
        {
            column = -1;
            cin.clear();
            cin.ignore();
            cout << "Invalid input please use integers" << endl;
        }
        if (board->playPiece(PlayerB, column)) break;

        board->printBoard(cout);
    }

    // Win message
    cout << "Congratulations ";
    if (currPlayer == PlayerA)
        cout << "Player A you win!" << endl;
    else
        cout << "Player B you win!" << endl;

    cout << "================================================================" << endl;

    // Reset or exit game
    delete board;
    cout << "Do you want to play another game of Connect 4 [y/n]" << endl;
    
    string repeat;
    cin.ignore();
    getline(cin, repeat);

    if (repeat.compare("y") != 0 && repeat.compare("yes") != 0)
        return 0;
    else
        goto start;

    return 0;
}