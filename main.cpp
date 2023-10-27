#include <iostream>
#include "A.h"
#include "FootballTeam/LLDB.cpp"
#include "FootballTeam/node.cpp"
using namespace std;

int main() {
    A a(1);
    A b(2);
    A c(3);
    A d(0);
    LLDB<A> v;
    node<A>* head = NULL;
    v.push_fr(head,a);
    v.push_fr(head,b);
    v.push_fr(head,c);
    v.insert(head,2,d);
    v.duyetxuoi(head);
    v.erase(head,3);
    // v.duyetxuoi(head);
    v.duyetnguoc(head);
    cout <<  v.size(head);
} 