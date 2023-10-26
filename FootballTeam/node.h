#include <iostream>
using namespace std;

class node
{
    public:
        template<typename T>
        T data;
        node* next;
        node* prev;
        node();
        ~node();       
};