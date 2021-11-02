#include <iostream>
#include "stack.h"


template<typename TS>
Stack<TS>::Stack()
{
    head = nullptr;
}

template<typename TS>
int Stack<TS>::AddItem(TS indata)
{
    Node<TS>* tmp = head;
    head = new Node<TS>(indata);
    head->SetNextNode(tmp);
    size++;
    return 0;
}

template<typename TS>
int Stack<TS>::GetItem()
{
    if(head != nullptr){
        Node<TS>* tmp = head;
        head = tmp->GetNextNode();
        size--;
        std::cout << head->getData();
        return 0;
    }
    else {
        return 1;
    }
}

template<typename TS>
void Stack<TS>::SetSize(int insize)
{
    size = insize;
}

template<typename TS>
int Stack<TS>::GetSize()
{
    return size;
}
