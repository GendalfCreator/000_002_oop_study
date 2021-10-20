#include <iostream>

using namespace std;

template <typename TN>
class Node{
public:
    Node(TN indata, int size, Node* inparent = nullptr, Node* inl_node = nullptr, Node* inr_node = nullptr);
    TN data;
    Node* l_node;
    Node* r_node;
    int index;
    Node<TN>* Get_Parent();
    void Set_Parent(Node* parent);
private:
    Node* parent;
};

template <typename T>
class BinaryTree{
public:
    BinaryTree ();
    void AddNode(T data);
    int Remove_Node(T indata);
    void Find_Node(T indata);
    int GetSize();
    Node<T>* GetRoot();
    void ShowTree(Node<T>* tmp);
    void Clear_Tree(Node<T>* tmp);
private:
    Node<T>* root;
    int size;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
    size = 0;
}

template<typename TN>
Node<TN>::Node(TN indata, int size, Node* inparent, Node* inl_node, Node* inr_node)
{
    data = indata;
    l_node = inl_node;
    r_node = inr_node;
    index = size++;
    parent = inparent;
}

template<typename TN>
Node<TN>* Node<TN>::Get_Parent()
{
    return parent;
}

template<typename TN>
void Node<TN>::Set_Parent(Node *parent)
{
    parent = parent;
}

template<typename T>
void BinaryTree<T>::AddNode(T data)
{
    if(root == nullptr){
        root = new Node<T>(data, size);
        size++;
    }
    else{
        Node<T>* tmp = root;
        while(tmp->l_node != nullptr || tmp->r_node != nullptr){
            if(tmp->data > data){
                if(tmp->l_node == nullptr){
                    break;
                }
                else if(tmp->l_node != nullptr){
                    tmp = tmp->l_node;
                }
            }
            else if(tmp->data < data){
                if(tmp->r_node == nullptr){
                    break;
                }
                else if(tmp->r_node != nullptr){
                    tmp = tmp->r_node;
                }
            }
            else{
                exit(1);
            }
        }
        if(tmp->data > data){
            tmp->l_node = new Node<T>(data, size, tmp);
            size++;
        }
        else if(tmp->data < data){
            tmp->r_node = new Node<T>(data, size, tmp);
            size++;
        }
    }
}

template<typename T>
int BinaryTree<T>::Remove_Node(T indata)
{
    Node<T>* tmp = root;

    while(tmp->data != indata){
        if(tmp->data < indata){
            tmp = tmp->r_node;
        }
        else if(tmp->data > indata){
            tmp = tmp->l_node;
        }
    }
    if(tmp == root){
        this->Clear_Tree(this->GetRoot());
    }
    else if(tmp != root){
        Node<T>* l_tmp = tmp->l_node;
        Node<T>* r_tmp = tmp->r_node;
        Node<T>* parent_tmp = tmp->Get_Parent();
        if(l_tmp == nullptr && r_tmp == nullptr){
            if(tmp->data > parent_tmp->data){
                parent_tmp->r_node = nullptr;
            }
            else if(tmp->data < parent_tmp->data){
                parent_tmp->l_node = nullptr;
            }
            delete tmp;
            size--;
        }
        else if(l_tmp == nullptr){
            parent_tmp->l_node = r_tmp;
            r_tmp->Set_Parent(parent_tmp);
            delete tmp;
            size--;
        }
        else if(r_tmp == nullptr){
            parent_tmp->l_node = l_tmp;
            l_tmp->Set_Parent(tmp->Get_Parent());
            delete tmp;
            size--;
        }
        else if(r_tmp != nullptr && l_tmp != nullptr){
            if(tmp->data < parent_tmp->data){
                parent_tmp->l_node = r_tmp;
                r_tmp->Set_Parent(parent_tmp);
                delete tmp;
                size--;

                tmp = r_tmp;
                while(tmp->l_node != nullptr){
                    tmp = tmp->l_node;
                }
                tmp->l_node = l_tmp;
            }
            else if(tmp->data > parent_tmp->data){
                parent_tmp->r_node = r_tmp;
                r_tmp->Set_Parent(tmp->Get_Parent());
                delete tmp;
                size--;

                tmp = r_tmp;
                while(tmp->l_node != nullptr){
                    tmp = tmp->l_node;
                }
                tmp->l_node = l_tmp;
            }
        }
    }
    return 0;
}

template<typename T>
void BinaryTree<T>::Find_Node(T indata)
{
    Node<T>* tmp = this->root;
    while(indata != tmp->data){
        if(tmp->data < indata){
            tmp = tmp->r_node;
        }
        else if(tmp->data > indata){
            tmp = tmp->l_node;
        }
    }
    cout << endl << "index = " << tmp->index << " -> data = " << tmp->data << endl;
}

template<typename T>
int BinaryTree<T>::GetSize()
{
    return size;
}

template<typename T>
Node<T>* BinaryTree<T>::GetRoot()
{
    return root;
}

template<typename T>
void BinaryTree<T>::ShowTree(Node<T>* tmp)
{
    if(tmp){
        cout << tmp->data;
        if(tmp->l_node || tmp->r_node){
            cout << "(";
            if(tmp->l_node){
                ShowTree(tmp->l_node);
            }
            else{
                cout << "NULL";
            }
            cout << ",";
            if(tmp->r_node){
                ShowTree(tmp->r_node);
            }
            else{
                cout << "NULL";
            }
            cout << ")";
        }
    }
}

template<typename T>
void BinaryTree<T>::Clear_Tree(Node<T>* tmp)
{
    if(tmp){
        if(tmp->l_node || tmp->r_node){
            if(tmp->l_node){
                Clear_Tree(tmp->l_node);
            }
            if(tmp->r_node){
                Clear_Tree(tmp->r_node);
            }
        }
    }
    delete tmp;
    size--;
}


int main()
{
    cout << "Hello World!" << endl;
    BinaryTree<int> tree;
    tree.AddNode(59);
    tree.AddNode(7);
    tree.AddNode(988);
    tree.AddNode(5);
    tree.AddNode(45);
    tree.AddNode(704);
    tree.AddNode(995);
    tree.AddNode(1);
    tree.AddNode(30);
    tree.AddNode(50);
    tree.AddNode(705);
    tree.AddNode(990);
    tree.AddNode(1015);
    cout << tree.GetSize() << endl;
    tree.ShowTree(tree.GetRoot());

    tree.Remove_Node(45);

    cout << endl << tree.GetSize() << endl;
    tree.ShowTree(tree.GetRoot());

    tree.Find_Node(988);
    return 0;
}



