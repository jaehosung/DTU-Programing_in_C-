// this is just a simple program to test your implementation
#include <iostream>
#include "vector2d.h"
// here we import the file that you need to implement
#include "vector2d.cpp"

using namespace std;

int main(){
    
    // we crate here some vectors with fixed values
    v2d v1(3,0);
    //v2d v2(0,4);
    //v2d v3(3,2);
    v2d v4(v1);
    return 0;
}
