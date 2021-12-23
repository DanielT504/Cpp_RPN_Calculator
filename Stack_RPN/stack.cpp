#include <iostream>
#include "stack.h"

using namespace std;

//constructor
Stack::Stack(){
    entered = 0;
    top = -1;
    for (int a = 0; a < SIZE; a++){
        nstack[a] = 0;
    }
}

//destructor
Stack::~Stack() {

}

//pushing a value onto the top of the stack
void Stack::push(float entered) {
    if (top < 20){
        top++;
        nstack[top] = entered;
    } else {
        cout << "Stack full.";
    }
}

//popping a value off of the stack
float Stack::pop() {
    float entered = nstack[top];
    top--;
    return entered;
}

//returning size of stack
int Stack::ntop() {
    return top;
}

//returning top value of stack
float Stack::req(int spot){
    return nstack[spot];
}
