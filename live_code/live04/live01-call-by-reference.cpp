#include <iostream>
using namespace std;

typedef struct intPair {
    int u;
    int v;
} intPair;

// swap in functional style (call-by-value)
intPair swap1(intPair input){
    intPair result;
    
    result.u = input.v;
    result.v = input.u;
    
    return result;
}

// swap in call-by-reference style
void swap2(int & x, int & y){
    int z;
    
    z = x;
    x = y;
    y = z;
}

// swap in indirect call-by-reference
// i.e. call-by-reference encoded with call-by-value using pointers
void swap3(int * x, int * y){
    int z;
    
    z  = *x;
    *x = *y;
    *y = z;
}


int main(void){
    int a, b, c;
    intPair p;
    
    a = 1;
    b = 2;
    cout << "Initial values" << endl;
    cout << "a,b = " << a << "," << b << endl;
    
    cout << "Swapping functional style\n";
    p.u = a;
    p.v = b;
    p = swap1(p);
    a = p.u;
    b = p.v;
    cout << "a,b = " << a << "," << b << endl;
    
    cout << "Swapping by reference\n";
    swap2(a,b);
    cout << "a,b = " << a << "," << b << endl;
    
    
    cout << "Swapping by reference (via pointers)\n";
    swap3(&a,&b);
    cout << "a,b = " << a << "," << b << endl;
    
}