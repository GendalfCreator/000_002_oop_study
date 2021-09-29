#include <iostream>

using namespace std;

template<typename T>
class List{
public:
    List();
    ~List();
    void Show_list();
    void Pop_front();
    void Pop_Back();
    int removeAt(int index);
    void Push_Front(T data);
    void Push_back(T data);
    int insert(T data, int index);
    void Clear();
    int GetSize(){return size;};
    T& operator[](const int index);
private:
    template<typename T1>
    class Node{
    public:
        Node* pNextNode;
        Node* pPrevNode;
        T1 data;

        Node (T1 data = T1(), Node* pNext=nullptr, Node* pPrev=nullptr) {
            this->data = data;
            this->pNextNode = pNext;
            this->pPrevNode = pPrev;
        }
    private:
    };
    Node<T>* head;
    int size;
};

template<typename T>
List<T>::List(){
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List(){
}

template<typename T>
void List<T>::Pop_front()
{
    Node<T>* tmp = this->head;
    this->head = tmp->pNextNode;
    this->head->pPrevNode = nullptr;
    delete tmp;
    this->size--;
}

template<typename T>
void List<T>::Push_back(T data)
{
    if (this->head == nullptr) {
        this->head = new Node<T>(data);
        this->size++;
    }
    else if (this->head != nullptr) {
        Node<T>* tmp = this->head;
        while (tmp->pNextNode != nullptr) {
            tmp = tmp->pNextNode;
        }
        tmp->pNextNode = new Node<T>(data, nullptr, tmp);
        this->size++;
    }
}

template<typename T>
void List<T>::Show_list()
{
    cout << "=========================\n";
    Node<T>* tmp = this->head;
    for (int i = 0; i < this->size; i++) {
        cout << "this = " << tmp << endl;
        cout << "prev = " << tmp->pPrevNode << endl;
        cout << "next = " << tmp->pNextNode << endl;
        cout << "data = " << tmp->data << endl;
        cout << "-----" << endl;
        tmp = tmp->pNextNode;
    }
}

template<typename T>
void List<T>::Clear()
{
    Node<T>* tmp = this->head;
    while(this->head != nullptr){
        tmp = this->head;
        this->head = tmp->pNextNode;
        delete tmp;
        this->size--;
    }
}

template<typename T>
T &List<T>::operator[](const int index)
{
    Node<T>* tmp = this->head;
    for(int i = 0; i < index - 1; i++){
        tmp = tmp->pNextNode;
    }
    return tmp->data;
}

template<typename T>
void List<T>::Push_Front(T data)
{
    this->head = new Node<T>(data, this->head, nullptr);
    this->head->pNextNode->pPrevNode = this->head;
    this->size++;
}

template<typename T>
void List<T>::Pop_Back()
{
    Node<T>* next = this->head;
    for(int i = 0; i < this->size - 1; i++){
        next = next->pNextNode;
    }
    Node<T>* prev = this->head;
    for(int i = 0; i < this->size - 2; i++){
        prev = prev->pNextNode;
    }
    prev->pNextNode = nullptr;
    delete next;
    this->size--;
}

template<typename T>
int List<T>::insert(T data, int index)
{
    if(index <= 0){
        return 1;
    }
    else if(index == 1){
        this->Push_Front(data);
    }
    else if(index > 1 && index <= this->size){
        Node<T>* prevNode = this->head;
        for(int i = 0; i < index - 2; i++){
            prevNode = prevNode->pNextNode;
        }
        Node<T>* nextNode = prevNode->pNextNode;
        Node<T>* tmp = new Node<T>(data, nextNode, prevNode);
        prevNode->pNextNode = tmp;
        nextNode->pPrevNode = tmp;
        this->size++;
    }
    else if(index > this->size){
        this->Push_back(data);
    }
    return 0;
}

template<typename T>
int List<T>::removeAt(int index)
{
    if(index <= 0){
        return 1;
    }
    else if(index == 1){
        this->Pop_front();
    }
    else if(index > 1 && index < this->size){
        Node<T>* tmp = this->head;
        for(int i = 0; i < index - 1; i++){
            tmp = tmp->pNextNode;
        }

        Node<T>* prev = tmp->pPrevNode;
        Node<T>* next = tmp->pNextNode;
        prev->pNextNode = next;
        next->pPrevNode = prev;

        delete tmp;
        this->size--;
        return 0;
    }
    else if(index == this->size){
        this->Pop_Back();
    }
    else if(index > this->size){
        return 1;
    }
    else {
        return 1;
    }
    return 0;
}

int main()
{
    List<int> lst;

    lst.Push_back(29);
    lst.Push_back(56);
    lst.Push_back(10);
    lst.Show_list();
    cout << lst[1] + lst[3] << endl;

    return 0;
}
