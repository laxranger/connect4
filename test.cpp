#include <iostream>
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
    // Test vertical win
    Board* test1 = new Board();
    assert(test1->playPiece(PlayerA, 0) == false);
    assert(test1->playPiece(PlayerA, 0) == false);
    assert(test1->playPiece(PlayerA, 0) == false);
    assert(test1->playPiece(PlayerA, 0) == true);
    test1->printBoard(cout);
    cout << "===============================" << endl;

    // Test horizontal win left
    Board* test2a = new Board();
    assert(test2a->playPiece(PlayerB, 0) == false);
    assert(test2a->playPiece(PlayerB, 1) == false);
    assert(test2a->playPiece(PlayerB, 2) == false);
    assert(test2a->playPiece(PlayerB, 3) == true);
    test2a->printBoard(cout);
    cout << "===============================" << endl;

    // Test horizontal win right
    Board* test2b = new Board();
    assert(test2b->playPiece(PlayerB, 3) == false);
    assert(test2b->playPiece(PlayerB, 2) == false);
    assert(test2b->playPiece(PlayerB, 1) == false);
    assert(test2b->playPiece(PlayerB, 0) == true);
    test2b->printBoard(cout);
    cout << "===============================" << endl;

     // Test horizontal win middle
    Board* test2c = new Board();
    assert(test2c->playPiece(PlayerB, 0) == false);
    assert(test2c->playPiece(PlayerB, 1) == false);
    assert(test2c->playPiece(PlayerB, 3) == false);
    assert(test2c->playPiece(PlayerB, 4) == false);
    assert(test2c->playPiece(PlayerB, 2) == true);
    test2c->printBoard(cout);
    cout << "===============================" << endl;

    // Test diagonal win real play scenario
    Board* test3a = new Board();
    assert(test3a->playPiece(PlayerA, 0) == false);
    assert(test3a->playPiece(PlayerB, 1) == false);
    assert(test3a->playPiece(PlayerA, 1) == false);
    assert(test3a->playPiece(PlayerB, 2) == false);
    assert(test3a->playPiece(PlayerA, 2) == false);
    assert(test3a->playPiece(PlayerB, 0) == false);
    assert(test3a->playPiece(PlayerA, 2) == false);
    assert(test3a->playPiece(PlayerB, 3) == false);
    assert(test3a->playPiece(PlayerA, 3) == false);
    assert(test3a->playPiece(PlayerB, 3) == false);
    assert(test3a->playPiece(PlayerA, 3) == true);
    test3a->printBoard(cout);
    cout << "===============================" << endl;

    // Test diagonal win reverse direction
    Board* test3b = new Board();
    assert(test3b->playPiece(PlayerA, 0) == false);
    assert(test3b->playPiece(PlayerA, 0) == false);
    assert(test3b->playPiece(PlayerA, 0) == false);
    assert(test3b->playPiece(PlayerB, 0) == false);
    assert(test3b->playPiece(PlayerA, 1) == false);
    assert(test3b->playPiece(PlayerA, 1) == false);
    assert(test3b->playPiece(PlayerB, 1) == false);
    assert(test3b->playPiece(PlayerA, 2) == false);
    assert(test3b->playPiece(PlayerB, 2) == false);
    assert(test3b->playPiece(PlayerB, 3) == true);
    test3b->printBoard(cout);
    cout << "===============================" << endl;

    // Test diagonal middle win reverse
    Board* test3c = new Board();
    assert(test3c->playPiece(PlayerA, 0) == false);
    assert(test3c->playPiece(PlayerA, 0) == false);
    assert(test3c->playPiece(PlayerA, 0) == false);
    assert(test3c->playPiece(PlayerB, 0) == false);
    assert(test3c->playPiece(PlayerA, 1) == false);
    assert(test3c->playPiece(PlayerA, 1) == false);
    assert(test3c->playPiece(PlayerA, 2) == false);
    assert(test3c->playPiece(PlayerB, 2) == false);
    assert(test3c->playPiece(PlayerB, 3) == false);
    assert(test3c->playPiece(PlayerB, 1) == true);
    test3c->printBoard(cout);
    cout << "===============================" << endl;

    // Test diagonal middle win
    Board* test3d = new Board();
    assert(test3d->playPiece(PlayerA, 0) == false);
    assert(test3d->playPiece(PlayerB, 1) == false);
    assert(test3d->playPiece(PlayerA, 1) == false);
    assert(test3d->playPiece(PlayerB, 2) == false);
    assert(test3d->playPiece(PlayerB, 0) == false);
    assert(test3d->playPiece(PlayerA, 2) == false);
    assert(test3d->playPiece(PlayerB, 3) == false);
    assert(test3d->playPiece(PlayerA, 3) == false);
    assert(test3d->playPiece(PlayerB, 3) == false);
    assert(test3d->playPiece(PlayerA, 3) == false);
    assert(test3d->playPiece(PlayerA, 2) == true);
    test3d->printBoard(cout);
    cout << "===============================" << endl;

    // Test out of bounds
    Board* test4 = new Board(3,3);
    assert(test4->playPiece(PlayerA, 0) == false);
    assert(test4->playPiece(PlayerA, 1) == false);
    assert(test4->playPiece(PlayerA, 2) == false);
    // Out of bounds low
    assert(test4->playPiece(PlayerA, -1) == false);
    // Out of bounds high
    assert(test4->playPiece(PlayerA, 3) == false);
    test4->printBoard(cout);
    cout << "===============================" << endl;

    cout << "All tests PASS!" << endl;
}