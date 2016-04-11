#include<iostream>
using namespace std;
int fibo(int n){
    if(n<=1){
        return 1;
    }else{
        return fibo(n-2)+fibo(n-1);
    }

}
int main(){
    while(cin.peek() != '\n'){
        int num;
        cin>>num;
        cout<<fibo(num)<<" ";
    }
    return 0;
}
