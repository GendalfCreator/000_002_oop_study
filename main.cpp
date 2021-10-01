#include <iostream>

using namespace std;


class Node;

template<typename T>
class BinaryTree{
public:
    int Add_Node(T data);
    void Remove_Node(int index);
    Node& Find_Node(T data);
    Node& operator[](int index);
    void Show_Tree();
    BinaryTree();
    ~BinaryTree();

private:
    template<typename T1>
    class Node{
    public:
        int index;
        T1 data;
        Node* l_node;
        Node* r_node;
        Node* root;

        Node(T1 data = T1(), int index = 0, Node* root = nullptr,
             Node* l_node = nullptr, Node* r_node = nullptr)
        {
            data = data;
            index = index;
            root = root;
            l_node = l_node;
            r_node = r_node;
        };
        ~Node();

    private:
    };

    Node<T>* root;
    int size;

};

template<typename T>
int BinaryTree<T>::Add_Node(T data)
{
    if(size == 0){
        root = new Node<T>(data);
        size++;
        return 0;
    }
    else if(size > 0){
        Node<T>* tmp = root;
        while(tmp->l_node != nullptr || tmp->r_node != nullptr){
            if(tmp->data < data){
                tmp = tmp->r_node;
            }
            else if(tmp->data > data){
                tmp = tmp->l_node;
            }
            else if(tmp->data == data){
                return 1;
            }
        }

        if(tmp->data < data){
            tmp->r_node = new Node<T>(data, size + 1, tmp);
            size++;
            return 0;
        }
        else if(tmp->data > data){
            tmp->l_node = new Node<T>(data, size + 1, tmp);
            size++;
            return 0;
        }
    }
}

template<typename T>
void BinaryTree<T>::Show_Tree()
{
    Node<T>* tmp = root;
    while(tmp->l_node == nullptr && tmp->r_node == nullptr){
        cout << tmp->data;
        Show_Tree();
    }
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
    size = 0;
}

int main()
{
    cout << "Hello World!" << endl;
    BinaryTree<int> tree;

    tree.Show_Tree();
    return 0;
}

