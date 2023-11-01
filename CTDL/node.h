#include <iostream>
using namespace std;
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
// <<<<<<< HEAD:FootballTeam/node.h
// #endif // A_H
// >>>>>>> 45ad9d4a219c42d290c0af62f34c877f53ac97f0
// =======
// >>>>>>> 848a7f4b79ce5551aadd78b84172b932fd51db6f:CTDL/node.h
