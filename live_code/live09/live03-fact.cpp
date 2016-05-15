#include <iostream>
using namespace std;

double fact(double n){
    if (n == 0) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}

int main(){
    
    double n;
    
    cout << "Give me a non-negative double: " ;
    cin >> n;
    cout << "Computing fact(" << n << ")... " << fact(n) << endl;

    return 0;
    
}
