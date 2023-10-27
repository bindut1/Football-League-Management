#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class LLDB
{
    private:
        node<T> *head;
        node<T> *tail;
    public:
        //template <typename T>
        LLDB();
        ~LLDB();
        template <typename T>
        node<T> *makenode(T); //tao node<T>
        int size(node*);    //kich thuoc danh sach
        template <typename T>   
        void push_fr(node**, T);    //them node<T> vao dau
        template <typename T>
        void push_b(node**, T);     //them node<T> vao cuoi
        template <typename T>
        void insert(node**, int, T);    //them node<T> vao vi tri bat ky
        void delete_fr(node**);     //xoa node dau
        void delete_b(node**);     //xoa node cuoi
        void erase(node**, int);    //xoa node o vi tri bat ky
        void duyetxuoi(node*);      //duyet danh sach theo chieu xuoi
        void duyetnguoc(node*);     //duyet danh sach theo chieu nguoc
        void sort(node*);       //sap xep danh sach
        // friend ostream& operator<<(ostream&, const node*);
        // friend istream& operator>>(istream&, node*);
};