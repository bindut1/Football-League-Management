#include "node.h"
#ifndef A_H
#define A_H
template<typename T>
node<T>::node(T t)
    :   data(t), next(NULL), prev(NULL)
{
    // cout << "Constructor of Node" << endl;
}
template<typename T>
node<T>::~node()
{
    cout << "Destructor of Node" << endl;
}
#endif // A_H