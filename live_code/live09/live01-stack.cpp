// Example of stack overflow
#include <iostream>
using namespace std;

int depth;

void f(){
//    int a[10000];
    cout << "depth " << depth << " reached...\n" ;
    depth++;
    f();
}

int main(){
    
    f();
    
    return 0;
}
