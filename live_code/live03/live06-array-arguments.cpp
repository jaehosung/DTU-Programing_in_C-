#include <iostream>
using namespace std;

void f(int a[]){
    a[0]=1;
    return;
}

void g(int *a){
    a[0]=1;
    return;
}


int main(void){
    int a[1];
    
    a[0]=0;
    cout << "Now a[0] is " << a[0] << endl;
    cout << "Passing array as value...\n";
    f(a);
    cout << "Now a[0] is " << a[0] << endl;

    cout << endl;
    a[0]=0;
    cout << "Now a[0] is " << a[0] << endl;
    cout << "Passing array as reference...\n";
    g(a);
    cout << "Now a[0] is " << a[0] << endl;
    
    return 0;
    
}

