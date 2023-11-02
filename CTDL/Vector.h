#ifndef V_H
#define V_H

template <typename T>
class Vector
{
private:
    T* p;
public:
    static int n;
    Vector();
    Vector(const Vector&);
    ~Vector();
    int size();
    bool empty();
    T& operator[](int);
    void push_back(const T&);
    void pop_back();
    void clear();
    bool contains(const T&);
    int find(const T&);
    void erase(int);
};

#endif