#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

template<typename TS>
class stack
{
public:
    stack();
    void addItem(TS inData);
    void useItem();
    int GetSize();
    ~stack();
private:
    node<TS>* head;
    int size;
};

template<typename TS>
stack<TS>::stack()
{
    head = nullptr;
    size = 0;
}

template<typename TS>
void stack<TS>::addItem(TS inData)
{
    node<TS>* tmp = head;
    head = new node<TS>(inData, tmp);
    size++;
}

template<typename TS>
void stack<TS>::useItem()
{
    node<TS>* tmp = head;
    head = tmp->GetNextNode();
    std::cout << "Running " << tmp->GetData() << std::endl;

    delete tmp;
    size--;
}

template<typename TS>
int stack<TS>::GetSize()
{
    return size;
}

template<typename TS>
stack<TS>::~stack()
{
    while(head != nullptr){
        node<TS>* tmp = head;
        delete tmp;
        size--;
        if(size == 0){
            head = nullptr;
        }
    }
}

#endif // STACK_H
