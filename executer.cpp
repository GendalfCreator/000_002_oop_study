#include <iostream>
#include "executer.h"
#include "node.h"

template<typename TE>
Executer<TE>::Executer()
{

}

template<typename TE>
int Executer<TE>::execItem(Node<TE> &initem)
{
    std::cout << "Execution data " << initem.getData();
    return 0;
}

