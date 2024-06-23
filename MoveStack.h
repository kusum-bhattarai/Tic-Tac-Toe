//Kusum Bhattarai Sharma
//xcm15
//04/29/2024

#ifndef MOVESTACK_H
#define MOVESTACK_H

#include <stack>

struct Move {
    int x;
    int y;
    Move() { x = 0; y = 0; }
    Move(int a, int b) { x = a; y = b; }
};

class MoveStack {
private:
    std::stack<Move> stack;

public:
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
};

#endif //MOVESTACK_H


