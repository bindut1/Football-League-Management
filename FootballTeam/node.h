#include <iostream>
using namespace std;
#ifndef A_H
#define A_H
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
#endif // A_H