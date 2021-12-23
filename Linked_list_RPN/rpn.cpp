#include <iostream>
#include <cmath>
#include "rpn.h"

using namespace std;

//constructor
Rpn::Rpn(){
    a = 0;
    b = 0;
}

//destructor
Rpn::~Rpn(){

}

//addition
void Rpn::add(){
    if (isEmpty2()){
        push(pop() + pop());
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//subtraction
void Rpn::subtract(){
    if (isEmpty2()){
        b = pop();
        a = pop();

        push(a - b);
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//multiplication
void Rpn::multiply(){
    if (isEmpty2()){
        push(pop() * pop());
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//division
void Rpn::divide(){
    if (isEmpty2()){
        b = pop();
        a = pop();

        if (b != 0){
            push(a / b);
        } else {
            cout << "Cannot divide by 0.";
        }
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//square root
void Rpn::squareRoot(){
    if (isEmpty1()){
        a = pop();

        if (a >= 0){
            push(sqrt(a));
        } else {
            cout << "Cannot root a negative number";
        }
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//sine in degrees
void Rpn::sine(){
    if (isEmpty1()){
        push(sin(pop() * M_PI / 180));
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//cosine in degrees
void Rpn::cosine(){
    if (isEmpty1()){
        push(cos(pop() * M_PI / 180));
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//tangent in degrees
void Rpn::tangent(){
    if (isEmpty1()){
        a = pop();

        if ((int(a) + 90) % 180 != 0){
            push(tan(a * M_PI / 180));
        } else {
            cout << "Not possible.";
        }
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//power
void Rpn::exponent(){
    if (isEmpty2()){
        b = pop();
        a = pop();

        push(pow(a, b));
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//absolute value
void Rpn::absoluteValue(){
    if (isEmpty1()){
        push(abs(pop()));
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//modulus
void Rpn::mod(){
    if (isEmpty2()){
        b = pop();
        a = pop();

        if (b != 0){
            push(int(a) % int(b));
        } else {
            cout << "Cannot divide by 0.";
        }
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//logarithm
void Rpn::log(){
    if (isEmpty2()){
        push(log10(pop()) / log10(pop()));
    } else {
        cout << "List does not contain enough values." << endl;
    }
}

//clear list
void Rpn::clearAll(){
    for (int i = nSize; i > -1; i--){
        pop();
    }
}

//delete tail
void Rpn::del(){
    pop();
}

//enter a number to the start of the list
void Rpn::oprt(float val){
    push(val);
}

//size of list
int Rpn::Head(){
    return nstart();
}

//peek tail
float Rpn::request(int spot){
    return req(spot);
}

//check if there is at least one value in the list
bool Rpn::isEmpty1(){
    if (nSize < 0){
        return false;
    } else {
        return true;
    }
}

//check if there is at least two values in the list
bool Rpn::isEmpty2(){
    if (nSize < 1){
        return false;
    } else {
        return true;
    }
}
