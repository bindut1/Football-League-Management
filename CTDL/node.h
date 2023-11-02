#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template<typename T>
class node
{
<<<<<<< HEAD
public:
    template <typename T>
    T data;
    node<T> *next;
    node<T> *prev;
    node<T>() : data(0), next(NULL), prev(NULL) {}
    node<T>(T value) : data(value), next(NULL), prev(NULL) {}
    ~node<T>() {}
};
=======
    public:
        T data;
        node* next;
        node* prev;
        node(T);
        ~node();       
};
<<<<<<< HEAD
#endif
=======
// <<<<<<< HEAD:FootballTeam/node.h
// #endif // A_H
// >>>>>>> 45ad9d4a219c42d290c0af62f34c877f53ac97f0
// =======
// >>>>>>> 848a7f4b79ce5551aadd78b84172b932fd51db6f:CTDL/node.h
>>>>>>> 4541cde14458c342589ef0acc6baf366fcb5c36e
