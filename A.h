#include <iostream>
using namespace std;

class A
{
private:
    int x;
public:
    A(int x = 1) {
        this->x = x;
    }
    ~A() {}
    friend ostream& operator<<(ostream& o, const A& a) {
        o << a.x << endl;
        return o;
    }
};

