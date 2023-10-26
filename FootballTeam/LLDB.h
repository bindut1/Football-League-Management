#include "node.h"
#include <iostream>
using namespace std;

class LLDB
{
    private:
        node *head;
        node *tail;
        //int size;
    public:
        //template <typename T>
        LLDB();
        ~LLDB();
        template <typename T>
        node *makenode(T); //tao node
        int size(node*);    //kich thuoc danh sach
        template <typename T>   
        void push_fr(node**, T);    //them node vao dau
        template <typename T>
        void push_b(node**, T);     //them node vao cuoi
        template <typename T>
        void insert(node**, int, T);    //them node vao vi tri bat ky
        void delete_fr(node**);     //xoa node dau
        void delete_b(node **);     //xoa node cuoi
        void erase(node**, int);    //xoa node o vi tri bat ky
        void duyetxuoi(node*);      //duyet danh sach theo chieu xuoi
        void duyetnguoc(node*);     //duyet danh sach theo chieu nguoc
        void sort(node*);       //sap xep danh sach
        friend ostream& operator<<(ostream&, const node*);
        friend istream& operator>>(istream&, node*);
};