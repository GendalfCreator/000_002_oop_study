#include "node.h"

template<typename TN>
Node<TN>::Node(TN indata, Node* innextnode)
{
    data = indata;
    nextNode = innextnode;
}

template<typename TN>
const Node<TN> &Node<TN>::GetNextNode()
{
    return nextNode;
}

template<typename TN>
void Node<TN>::SetNextNode(Node *innextnode)
{
    nextNode = innextnode;
}

template<typename TN>
TN Node<TN>::getData()
{
    return data;
}
