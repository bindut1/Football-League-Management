#include "LLDB.h"
#include <iostream>
using namespace std;
template <typename T>
LLDB<T>::LLDB()
{
    // cout << "Constructor of LLDB" << endl;
}
template <typename T>
LLDB<T>::~LLDB()
{
    // cout << "Destructor of LLDB" << endl;
}

template <typename T>
node<T>* LLDB<T>::makenode(T x)
{
    node<T>* new_node = new node<T>(x);
    return new_node;
}
template <typename T>
int LLDB<T>::size(node<T>* head)
{
    int cnt = 0;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;    
}

template <typename T>
void LLDB<T>::push_fr(node<T>*& head,T x)
{
    node<T> *new_node = makenode(x);
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}   

template <typename T>
void LLDB<T>::push_b(node<T>*& head, T x)
{
    node<T> *new_node = makenode(x);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node<T> *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
}

template <typename T>
void LLDB<T>::insert(node<T>*& head, int k, T x)
{
    int n = LLDB::size(head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1)
        LLDB::push_fr(head, x);
    else if (k == n + 1)
        LLDB::push_b(head, x);
    else
    {
        node<T> *tmp = head;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        node<T> *new_node = makenode(x);
        new_node->next = tmp->next;
        tmp->next->prev = new_node;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}
template <typename T>
void LLDB<T>::delete_fr(node<T>*& head)
{
    if (head == NULL)
        return;
    node<T> *tmp = head;
    head = (head)->next;
    if (head != NULL)
        head->prev = NULL;
    delete(tmp);
}
template <typename T>
void LLDB<T>::delete_b(node<T>*&head)
{
    if (head == NULL)
        return;
    node<T> *tmp = head;
    if (tmp->next == NULL)
    {
        head = NULL;
        delete(tmp);
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->prev->next = NULL;
    delete(tmp);
}
template <typename T>
void LLDB<T>::erase(node<T>*& head, int k)
{
    int n = LLDB<T>::size(head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        delete_fr(head);
    else
    {
        node<T> *tmp = head;
        for (int i = 1; i <= k - 1; i++)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete(tmp);
    }
}
template <typename T>
void LLDB<T>::duyetxuoi(node<T>* head)
{
    while (head != NULL)
    {
       cout << head->data; //?????????
        head = head->next;
    }
}
template <typename T>
void LLDB<T>::duyetnguoc(node<T>* head)
{
    if (head == NULL)
        return;
    while (head->next != NULL)
        head = head->next;
    while (head != NULL)
    {
       cout << head->data; //?????????
        head = head->prev;
    }
}

/* void LLDB::sort(node* head)
{
    for (node *i = *head; i != NULL; i = i > head->next)
    {
        node *min = i;
        for (int *j = i->next; j != NULL; j = j->next)
        {
            if (min->data > j->data)
                min = j;
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
} */