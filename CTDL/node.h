#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template<typename T>
class node
{
    public:
        T data;
        node* next;
        node* prev;
        node(T);
        ~node();       
};
#endif