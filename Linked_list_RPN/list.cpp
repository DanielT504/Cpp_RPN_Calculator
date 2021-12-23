#include <iostream>
#include "list.h"

using namespace std;

//constructor
List::List(){
    entered = 0;
    head = NULL;
    nSize = -1;
}

//destructor
List::~List(){

}

//function that pushes a user-entered value onto the head of the linked list
void List::push(float entered){
    NODE *newNode = new NODE;
    newNode->value = entered;
    newNode->next = head;

    head = newNode;

    nSize++;
}

//function that returns the value of the first node in the linked list,
//then deletes that node
float List::pop(){
    NODE *temp = new NODE;
    temp = head;

    entered = head->value;

    nSize--;

    head = head->next;

    delete temp;

    return entered;
}

//function that returns the number of nodes in the current linked list
int List::nstart(){
    return nSize;
}

//function that returns the value of a specified node in the linked list
float List::req(int spot){
    NODE *temp = new NODE;
    temp = head;

    for (int x = 0; x < spot; x++){
        temp = temp->next;
    }

    return temp->value;
}
