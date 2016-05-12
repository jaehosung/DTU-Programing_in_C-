#include <iostream>
using namespace std;

// factorial function
int fact(int n){
    
    int result;
    int i;
    
    result=1;

    for(i=1; i<=n; i++){
        result = result * i;
    }
    return result;
}

// choose based on factorial
int choose1(int n, int k){

    return fact(n)/(fact(n-k)*fact(k));

}

// choose based on http://en.wikipedia.org/wiki/Binomial_coefficient#Multiplicative_formula
int choose2(int n, int k){

    int result;
    int i;
    
    result=1;

    for(i=1; i<=k; i++){
        result = result * ( ((n+1)-i) / (double)i);
    }
    
    return result;

}

int main(){
    
    int n = 0;
    int k = 0;
    
    cout << "Please enter n and k in what follows:" << endl;
    cout << "n = " ;
    cin >> n;
    cout << "k = " ;
    cin >> k;
    cout << "Results computed with several functions:\n" ;
    cout << "(1) " << choose1(n,k) << endl;
    cout << "(2) " << choose2(n,k) << endl;
    return 0;
}

