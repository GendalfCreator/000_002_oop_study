#ifndef EXECUTER_H
#define EXECUTER_H

#include "node.h"

template<typename TE>
class Executer{
public:
    Executer();
    int execItem(Node<TE> &initem);
private:
};

#endif // EXECUTER_H
