#include <iostream>


using namespace std;

// Sieve of Eratosthenes
// http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Note that the second argument is an array of boolean values
void sieve(int n, bool *primes){
    
    // initialise the array (all numbers may be primes)
    for (int i=0; i<=n; i++){
        primes[i]=true;
    }
    
    // 0 and 1 are not primes
    primes[0]=false;
    primes[1]=false;
    
    // We could start the sieve from 2, but we start from 0
    for (int i=0; i<=n; i++){
        // if i is a prime
        if (primes[i]){
            // mark all j that divide by i as non-primes
            for(int j=i+i; j<=n; j=j+i){
                primes[j]=false;
            }
        }
    }

    return;
}

void display(int n, bool primes[]){
    
    bool found = false; // No prime found so far
    
    cout << "Displaying primes in 0.." << n << endl;
    for (int i=0; i<=n; i++){
        // if i is a prime
        if (primes[i]){
            // preceed by blank if i it's not the first prime
            if (found) {
                cout << " ";
            }
            // output the prime i
            cout << i ;
            // Remember that we found at least one prime
            found=true;
        }
    }
    cout << endl;
    
    cout << "Displaying the prime array..." << endl;
    for (int i=0; i<=n; i++){
        cout << primes[i] ;
        if ((i+1)%1000==0){

        }
    }
    
    cout << endl;

    return;
}

int main(){
    
    int n = 0;
    
    cout << "Maximum (potential) prime you want to see? ";
    cin >> n;
    
    // allocate boolean array of n+1 numbers 0..n
    bool primes[n+1];
    // again, this is not very standard
    // we will see later how to do it the right way (with dynamic allocation)
    // bool * primes = new bool[n+1];
    // and later (when primes is no more needed)
    // delete [] primes;
    
    sieve(n,primes);
    display(n,primes);
    
    return 0;
}

