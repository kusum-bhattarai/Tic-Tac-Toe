//Kusum Bhattarai Sharma
//xcm15
//Date: 04/29/2024


#include <iostream>
#include <sstream>
using namespace std;

#include "GameState.h"

int main() {
    GameState gameState;
    gameState.displayBoardState(cout);
    cout << "current player: " << gameState.getCurrentPlayer() << endl;

    int added = gameState.addMove(Move(1, 1));
    cout << added << " should be 1" << endl;
    gameState.displayBoardState(cout);
    cout << "current player: " << gameState.getCurrentPlayer() << endl;

    added = gameState.addMove(Move(1, 1)); // invalid move
    gameState.displayBoardState(cout);
    cout << added << " should be -1" << endl;

    int addedArray[8];
    addedArray[0] = gameState.addMove(Move(2, 2));
    addedArray[1] = gameState.addMove(Move(2, 0));
    addedArray[2] = gameState.addMove(Move(0, 2));
    addedArray[3] = gameState.addMove(Move(1, 2));
    addedArray[4] = gameState.addMove(Move(1, 0));
    addedArray[5] = gameState.addMove(Move(2, 1));
    addedArray[6] = gameState.addMove(Move(0, 1));
    addedArray[7] = gameState.addMove(Move(0, 0)); // draw
    
    gameState.displayBoardState(cout);
    for (int i = 0; i < 8; ++i)
        cout << addedArray[i] << " ";
    cout << endl;

    GameState gameState1;
    gameState1.addMove(Move(2, 2));
    bool undid = gameState1.undoLast();
    cout << boolalpha << undid << endl;
    undid = gameState1.undoLast();
    cout << boolalpha << undid << endl;
}

/* expected output:
___
___
___
current player: 0
1 should be 1
___
_x_
___
current player: 1
___
_x_
___
-1 should be -1
xoo
oxx
xxo
1 1 1 1 1 1 1 0
true
false
 */
