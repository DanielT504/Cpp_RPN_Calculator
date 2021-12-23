#ifndef LIST_H
#define LIST_H

//class to create linked list

class List
{
private:
    //linked list structure
    struct NODE {
        float value;
        NODE *next;
    };

    //user-entered value
    float entered;
    //head of linked list
    NODE *head;
public:
    List();
    ~List();
    float pop();
    void push(float entered);
    int nstart();
    int nSize;
    float req(int spot);
};

#endif

