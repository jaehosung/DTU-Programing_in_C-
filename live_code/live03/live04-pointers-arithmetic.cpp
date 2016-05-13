#include <iostream>
using namespace std;


int main(){
    
    cout << "A memory address in this computer uses ";
    cout << 8 * sizeof( nullptr ) << " bits" << endl;
    cout << endl;
    
    int x,y;

    cout << "Variable x is residing in address ";
    cout << (long)&x << endl;
    cout << "Variable y is residing in address ";
    cout << (long)&y << endl;
    cout << endl;
    
    int u,v;
    
    u = 23;
    cout << "The value of variable u is ";
    cout << u << endl;
    cout << "The value of variable u is ";
    cout << *&u << endl;
    cout << "The value of variable u is ";
    cout << *&*&u << endl;
    //...
    cout << endl;
    
    cout << "Variable u is residing in address ";
    cout << (long)&u << endl;
    cout << "Variable u is residing in address ";
    cout << (long)&*&u << endl;
    cout << "Variable u is residing in address ";
    cout << (long)&*&*&u << endl;
    //...
    cout << endl;
    
    u = 23;
    v = 17;
    cout << "The value of variable u is ";
    cout << u << endl;
    cout << "The value of variable v is ";
    cout << v << endl;
    
    int * p = & u;
    cout << "p points an integer of value ";
    cout << * p <<"     "<<(long)p<< endl;
    p = & v;
    cout << "and now p points an integer of value ";
    cout << * p <<"     "<<(long)p<< endl;

    // updating v through via pointer p
    (*p) = (*p) + 1;
    cout << "The value of variable u is ";
    cout << u << endl;
    cout << "The value of variable v is ";
    cout << v << endl;
    
    return 0;
    
}
