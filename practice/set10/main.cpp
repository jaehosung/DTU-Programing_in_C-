#include <iostream>
#include "doubly-linked.h"
#include "doubly-linked.cpp"

using namespace std;
 
int main(void){
     
    List l;
    int n;
     
    while(cin.peek() != '\n'){
        cin>>n;
        l.insert(n);
    }
     
    // Print list as read from cin
    l.print();
    // Reverse the list and print it
    l.reverse();
    l.print();
    // Reverse again and print it
    l.reverse();
    l.print();
     
    return 0;
     
}
