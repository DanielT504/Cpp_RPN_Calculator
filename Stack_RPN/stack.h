#ifndef STACK_H
#define STACK_H

//predetermined stack size
#define SIZE 20

//class to create stack

class Stack
{
private:
    //user-entered value
    float entered;
    //stack
    float nstack[SIZE];
public:
    Stack();
    ~Stack();
    float pop();
    void push(float entered);
    int ntop();
    int top;
    float req(int spot);
};

#endif

