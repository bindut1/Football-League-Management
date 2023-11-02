#include <iostream>
using namespace std;
class VectorPair
{
private:
    string name;
    int total;
public:
    VectorPair(string = "",int = 0);
    ~VectorPair();
    string getName();
    int getTotal();
    void setName(string);
    void setTotal(int);
};

VectorPair::VectorPair(string name,int total) {
    this->name = name;
    this->total = total;
}

VectorPair::~VectorPair() {

}

string VectorPair::getName() {
    return this->name;
} 

int VectorPair::getTotal() {
    return this->total;
}

void VectorPair::setName(string name) {
    this->name = name;
}

void VectorPair::setTotal(int total) {
    this->total = total;
}