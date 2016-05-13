#include <iostream>
using namespace std;

typedef struct {
    int u;
    int v;
} intPair ;

// increment a pair of values by value
intPair inc_both1(int x, int y){
    intPair result;
    
    result.u = x + 1;
    result.v = y + 1;
    
    return result;
}

// increment a pair of values by reference
void inc_both2(int & x, int & y){
    x = x + 1;
    y = y + 1;
}

// increment a pair of values by reference
// call-by-reference encoded with pointers
void inc_both3(int * x, int * y){
    (*x) = (*x) + 1;
    (*y) = (*y) + 1;
}


int main(void){
    int a = 0;
    int b = 0;
    int c = 0;
    intPair p;
    
    cout << "Example of incrementing two values with call-by-value\n";
    a = 0;
    b = 0;
    c = 0;
    cout << "a,b,c = " << a << "," << b << "," << c << " (initially) " << endl;
    p = inc_both1(a,b);
    a=p.u;
    b=p.v;
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing a,b) " << endl;
    p=inc_both1(b,c);
    b=p.u;
    c=p.v;
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing b,c) " << endl;
    
    cout << "Example of incrementing two values with call-by-reference\n";
    a = 0;
    b = 0;
    c = 0;
    cout << "a,b,c = " << a << "," << b << "," << c << " (initially) " << endl;
    inc_both2(a,b);
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing a,b) " << endl;
    inc_both2(b,c);
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing b,c) " << endl;


    cout << "Example of incrementing two values with call-by-reference via pointers\n";
    a = 0;
    b = 0;
    c = 0;
    cout << "a,b,c = " << a << "," << b << "," << c << " (initially) " << endl;
    inc_both3(&a,&b);
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing a,b) " << endl;
    inc_both3(&b,&c);
    cout << "a,b,c = " << a << "," << b << "," << c << " (after incrementing b,c) " << endl;

    return 0;
    
}

