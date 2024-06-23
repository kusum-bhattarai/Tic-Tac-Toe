// Filename MoveStack.cpp
// Author: Kusum Bhattarai Sharma 
// Date: 04/29/2024
// Assignment Number: 4
// Instructor: Xiaomin Li
//
// MoveStack A regular stack that stores instances of the Move structure. 
// A Move records the coordinates of the 'x' or 'o' token placed on the game board. 
// All past moves are stored here. The stack is required in order to be able to undo moves.


#include <cassert>
using namespace std;

#include "MoveStack.h"


MoveStack::MoveStack() {}

MoveStack::~MoveStack() {
    while (!stack.empty()) {
        stack.pop();
    }
}

int MoveStack::getSize() {
    return stack.size();
}

Move MoveStack::top() {
    return stack.top();
}

void MoveStack::push(Move move) {
    stack.push(move);
}

void MoveStack::pop() {
    if (!stack.empty()) {
        stack.pop();
    }
}