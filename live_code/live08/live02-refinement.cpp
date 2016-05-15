#include <iostream>

using namespace std;

class A {
public:
    void f(void) { cout << "Calling A::f\n"; };
    virtual void g(void) { cout << "Calling A::g\n"; };
    
};

class B : public A {
public:
    void f(void) { cout << "Calling B::f\n"; };
    void g(void) { cout << "Calling B::g\n"; };
};

int main(void){
    B b;
    A* p = &b;
    b.f();  // calls B::f()
    p->f(); // calls A::f()
    // due to static binding based on p’s type
    b.g();  // calls B::g()
    p->g(); // calls B::g()
    // due to dynamic binding based on p’s pointed object class
}