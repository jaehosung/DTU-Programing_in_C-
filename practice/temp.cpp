#include<iostream>
using namespace std;

void swap(int&x, int&y);

int main(){
    int a = 1;
    int b = 2;
    swap(a,b);
    cout<<a<<b<<endl;
}

void swap(int& x,int& y){
    int z;
    cout<<"what";
    z=x;
    x=y;
    y=z;
}
