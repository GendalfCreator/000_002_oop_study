#ifndef NODE_H
#define NODE_H

template<typename TN>
class node
{
public:
    node(TN inData, node<TN>* inNextNode = nullptr);
    node<TN>* GetNextNode();
    TN GetData();
private:
    node<TN>* nextNode;
    TN data;
};

template<typename TN>
node<TN>::node(TN inData, node<TN> *inNextNode)
{
    data = inData;
    nextNode = inNextNode;
}

template<typename TN>
node<TN> *node<TN>::GetNextNode()
{
    return nextNode;
}

template<typename TN>
TN node<TN>::GetData()
{
    return data;
}



#endif // NODE_H
