#include "LLDB.h"
#include <iostream>
using namespace std;

LLDB::LLDB()
    : head(NULL), tail(NULL)
{
    cout << "Constructor of LLDB" << endl;
}

LLDB::~LLDB()
{
    cout << "Destructor of LLDB" << endl;
}

template <typename T>
node LLDB::*makenode(T x)
{
    node *new_node = new node(x);
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int LLDB::size(node* head)
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
void LLDB::push_fr(node** head, T x)
{
    node *new_node = makenode(x);
    new_node->next = (*head);
    if (*head != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}   

template <typename T>
void LLDB::push_b(node** head, T x)
{
    node *new_node = makenode(x);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
}

template <typename T>
void LLDB::insert(node **head, int k, T x)
{
    int n = LLDB::size(*head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1)
        LLDB::push_fr(head, x);
    else if (k == n + 1)
        LLDB::push_b(head, x);
    else
    {
        node *tmp = (*head);
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        node *new_node = makenode(x);
        new_node->next = tmp->next;
        tmp->next->prev = new_node;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

void LLDB::delete_fr(node** head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    delete(tmp);
}

void LLDB::delete_b(node** head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    if (tmp->next == NULL)
    {
        *head = NULL;
        delete(tmp);
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    node *last = tmp->next;
    tmp->next = NULL;
    delete(last);
}

void LLDB::erase(node** head, int k)
{
    int n = LLDB::size(*head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        delete_fr(head);
    else
    {
        node *tmp = *head;
        for (int i = 1; i <= k - 1; i++)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete(tmp);
    }
}

void LLDB::duyetxuoi(node* head)
{
    while (head != NULL)
    {
    //    cout << head->data; //?????????
        head = head->next;
    }
}

void LLDB::duyetnguoc(node* head)
{
    if (head == NULL)
        return;
    while (head->next != NULL)
        head = head->next;
    while (head != NULL)
    {
    //    cout << head->data; //?????????
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