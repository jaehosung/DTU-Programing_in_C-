#include<iostream>
using namespace std;

// Sum of arithmetic series 1..n, i.e. 1+..+n

// smart implementation :)
unsigned int sum_fast(unsigned int n){
    
    return (n* (n+1.0)) / 2 ;
    
}

// iterative implementation
unsigned int sum_iter(unsigned int n){
    
    unsigned int sum = 0;
    for(unsigned int i=1; i<=n; i++){
        sum += i;
    }

    return sum;
}

// Three different implementations using recursion

unsigned int sum_rec1(unsigned int n){
    unsigned int r = 0;
    if (n > 0) {
        r = sum_rec1(n-1);
    }
    r = r + n;
    return r;
}

unsigned int sum_rec2(unsigned int n){
    if (n == 0) {
        return 0;
    } else {
        return n + sum_rec2(n-1);
    }
}

unsigned int sum_rec3(unsigned int n, unsigned int r=0){
    if (n==0) {
        return r;
    }
    return sum_rec3(n-1,n+r);
}


int main(){
    
    unsigned int n;

    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (-O3)
    cout << "Give me a non-negative integer: " ;
    cin >> n;
    cout << "Computing sum(1.." << n << ") using sum_fast... ";
    cout << sum_fast(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_iter... ";
    cout << sum_iter(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec3... ";
    cout << sum_rec3(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec2... ";
    cout << sum_rec2(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec1... ";
    cout << sum_rec1(n) << endl;
    
    return 0;
}
