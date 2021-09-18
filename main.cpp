#include <iostream>

using namespace std;

template<typename T>
class List{
public:
    List();
    ~List();
    void Pop_front();
    void Push_back(T data);
    int GetSize(){return size;};
    void Show_list();
    void Clear();
    void Push_Front(T data);
    void Pop_Back();
    int insert(T data, int index);
    int removeAt(int index);
    T& operator[](const int index);
private:
    template<typename T1>
    class Node{
    public:
        Node* pNextNode;
        T1 data;
        Node (T1 data = T1(), Node* pNext=nullptr){
            this->data = data;
            this->pNextNode = pNext;
        }
    private:

    };

    Node<T> *head;
    int size;
};

template<typename T>
List<T>::List(){
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List(){
    this->Clear();
}

template<typename T>
void List<T>::Pop_front()
{
    Node<T> *tmp = head;
    this->head = head->pNextNode;
    delete tmp;
    this->size--;
}

template<typename T>
void List<T>::Push_back(T data)
{
    if(head ==nullptr){
        head = new Node<T>(data);
    }
    else{
        Node<T> * current = this->head;
        while(current->pNextNode != nullptr){
            current = current->pNextNode;
        }
        current->pNextNode = new Node<T>(data);
    }
    this->size++;
}

template<typename T>
void List<T>::Show_list()
{
    for(int i = 0; i < this->size; i++){
        cout << this->operator[](i) << " ";
    }
    cout << endl;

    cout << this->size << " elements in list" << endl;
}

template<typename T>
void List<T>::Clear()
{
    while (size) {
        Pop_front();
    }
}

template<typename T>
void List<T>::Push_Front(T data)
{
    this->head = new Node<T>(data, this->head);
    this->size++;
}

template<typename T>
void List<T>::Pop_Back()
{
    Node<T>* tmp = this->head;
    while (tmp->pNextNode != nullptr) {
        tmp = tmp->pNextNode;
    }

    Node<T>* previous = this->head;
    for (int i = 0; i < this->size - 1; i++) {
        previous = previous->pNextNode;
    }

    previous->pNextNode = nullptr;
    delete tmp;
    this->size--;
}

template<typename T>
int List<T>::insert(T data, int index)
{
    if (index < 0) {
        return 1;
    }
    else if (index == 0) {
        this->Push_Front(data);
    }
    else if (index == this->size) {
        this->Push_back(data);
    }
    else if (index > 0 && index < this->size) {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNextNode;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNextNode);
        previous->pNextNode = newNode;
        this->size++;
    }
    return 0;
}

template<typename T>
int List<T>::removeAt(int index)
{
    if (index < 0) {
        return 1;
    }
    else if (index == 0) {
        this->Pop_Back();
        return 0;
    }
    else if (index > 0 && index < this->size) {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNextNode;
        }
        Node<T>* toDelete = previous->pNextNode;
        previous->pNextNode = toDelete->pNextNode;
        delete toDelete;
        this->size--;
        return 0;
    }
    else if (index == this->size) {
        this->Pop_front();
        return 0;
    }
    return 0;
}

template<typename T>
T &List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr){
        if(counter == index){
            return current->data;
        }
        current = current->pNextNode;
        counter++;
    }
}

int main()
{
    List<int> lst;

    lst.Push_Front(999);
    lst.Push_back(2);
    lst.Push_back(10);
    lst.Push_back(22);
    lst.Push_back(34);
    lst.Push_back(56);

    lst.Show_list();
    lst.removeAt(3);
    lst.Show_list();
    return 0;
}
