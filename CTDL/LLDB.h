#include "node.h"
#include <iostream>
using namespace std;
template <typename T>
class LLDB
{
    private:
        node<T> *head;
        node<T> *tail;
        //int size;
    public:
        // template <typename T>
        LLDB();
        ~LLDB();
        node<T>* makenode(T); //tao node
        int size(node<T>*);  //kich thuoc danh sach
        void push_fr(node<T>*&, T);    //them node vao dau
        void push_b(node<T>*&, T);     //them node vao cuoi
        void insert(node<T>*&, int, T);    //them node vao vi tri bat ky
        void delete_fr(node<T>*&);     //xoa node dau
        void delete_b(node<T>*&);     //xoa node cuoi
        void erase(node<T>*&, int);    //xoa node o vi tri bat ky
        void duyetxuoi(node<T>*);      //duyet danh sach theo chieu xuoi
        void duyetnguoc(node<T>*);     //duyet danh sach theo chieu nguoc
        // void sort(node<T>*);       //sap xep danh sach
        // friend ostream& operator<<(ostream&, const node*);
        // friend istream& operator>>(istream&, node*);
};