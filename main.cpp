#include <iostream>
#include "node.h"
#include "stack.h"

using namespace std;

int main()
{
    stack<int> testStack;

    testStack.addItem(2);
    testStack.addItem(4);
    testStack.addItem(45);
    testStack.addItem(765);
    testStack.addItem(331);

    while(testStack.GetSize()){
        testStack.useItem();
    }

    return 0;
}
