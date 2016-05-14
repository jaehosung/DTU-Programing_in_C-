#include <iostream>
#include <string>

// Here I include the header of my libary
//#include "live02-my_sweet_library.h"
// I don't need to include the implementation
// if my compiler knows how to compile and link it
#include "live02-my_sweet_library.h"

using namespace std;

int main(){
    
    string s;
    
    while(true){
        cout << "Give me a word: ";
        cin >> s;
        
        // I use here some functions of my sweet library
        cout <<       sweet(cool(s))  << endl;
        cout <<       cool(sweet(s))  << endl;
        cout << weird(cool(sweet(s))) << endl;
    }
    
    return 0;
}

