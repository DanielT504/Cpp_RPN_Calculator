#ifndef RPN_H
#define RPN_H
#include "stack.h"

//class to do calculations

//inherited stack class
class Rpn : public Stack {
private:
    bool isEmpty1();
    bool isEmpty2();
    //buffers
    float a, b;
public:
Rpn();
    ~Rpn();
    void add();
    void subtract();
    void multiply();
    void divide();
    void squareRoot();
    void sine();
    void cosine();
    void tangent();
    void exponent();
    void absoluteValue();
    void mod();
    void log();
    void clearAll();
    void del();
    void oprt(float val);
    int Top();
    float request(int spot);
};

#endif
