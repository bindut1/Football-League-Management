#include "node.h"

node::node()
    :   data(v), next(NULL), prev(NULL)
{
    cout << "Constructor of Node" << endl;
}

node::node()
{
    cout << "Destructor of Node" << endl;
}
