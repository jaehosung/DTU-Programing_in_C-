#include<iostream>
using namespace std;
int main(){
    int a =30;
    int &rep = a;
    a++;
    cout<<rep;
    return 0;
}
