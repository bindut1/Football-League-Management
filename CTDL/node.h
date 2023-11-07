#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template<typename T>
class node
{

public:
    template <typename T>
    T data;
    node<T> *next;
    node<T> *prev;
    node<T>() : data(0), next(NULL), prev(NULL) {}
    node<T>(T value) : data(value), next(NULL), prev(NULL) {}
    ~node<T>() {}
};


#endif