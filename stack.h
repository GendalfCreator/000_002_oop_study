#ifndef STACK_H
#define STACK_H
#include "node.h"

template<typename TS>
class Stack{
public:
    Stack();
    const Node<TS>& GetHead();
    int AddItem(TS indata);
    int GetItem();
    void SetSize(int insize);
    int GetSize();
    ~Stack();
private:
    Node<TS>* head;
    int size;
};

#endif // STACK_H
