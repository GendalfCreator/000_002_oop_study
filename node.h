#ifndef NODE_H
#define NODE_H


template<typename TN>
class Node{
public:
    Node(TN indata, Node* innextnode = nullptr);
    const Node<TN>& GetNextNode();
    void SetNextNode(Node* innextnode);
    TN getData();
private:
    TN data;
    Node<TN>* nextNode;
};

#endif // NODE_H
