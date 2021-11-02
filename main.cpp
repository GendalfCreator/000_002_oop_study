#include <iostream>
#include "node.h"
#include "stack.h"
#include "executer.h"
#include "testclass.h"

using namespace std;

int main()
{
    TestClass test;
    test.Exec();

    Node<int> node(45);

//    cout << node.getData() << endl;
//    Stack<int> Stack;

//    Stack.AddItem(34);
//    Stack.AddItem(76);
//    Stack.AddItem(985);

//    while(Stack.GetSize() !=0){
//        Stack.GetItem();
//    }



    return 0;
}
