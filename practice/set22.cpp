#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0){
        n /=2;
        cout<<n*(n+1);
    }else{
        n = (n-1)/2;
        cout<<n*(n+1);
    }
    return 0;
}
