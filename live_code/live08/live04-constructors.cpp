#include <iostream>

using namespace std;

class A {
public:
    A(int x, int y) {
        this->x = x;
        this->y = y;
    };
    int x;
    int y;
};

class B : public A {
public:
    // note that B's constructor
    // needs to invoke of of A's constructor first
    B(int x, int z) : A(x,0) {
        this->x = x;
        this->z = z;
    };
    int z;
};

int main(void){
    B b(0,1);
    A a(1,1);
    a = b;
    cout<<a.x<<a.y;
}