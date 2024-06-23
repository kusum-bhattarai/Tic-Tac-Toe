//Kusum Bhattarai Sharma
//xcm15  
//04/29/2024

#include <iostream>
#include "MoveStack.h"

using namespace std;


int main () {
    
    MoveStack moveStack;
    
    cout << "move stack size: " << moveStack.getSize() << endl;

    cout << "test 3 pushes to stack" << endl;
    moveStack.push(Move(0,0));
    moveStack.push(Move(1,1));
    moveStack.push(Move(2,2));
    
    cout << "test top and 1 pop from stack" << endl;
    Move m1 = moveStack.top();
    cout << m1.x << " " << m1.y << endl;
    moveStack.pop();
    Move m2 = moveStack.top();
    cout << m2.x << " " << m2.y << endl;
    
    cout << "move stack size: " << moveStack.getSize() << endl;
    
    moveStack.push(Move(1,0));
    cout << "move stack size: " << moveStack.getSize() << endl;

}

/* expected output
 
move stack size: 0
test 3 pushes to stack
test top and 1 pop from stack
2 2
1 1
move stack size: 2
move stack size: 3

 */



