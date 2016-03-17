#include<iostream>
using namespace std;
double pi(int n){
    int i;
    double pi=0;
    double k = 1;
    for(i=0;i<=n;i++){
        if(i%2==0){
            pi+=k/(2*i+1);
        }else{
            pi-=k/(2*i+1);
        }
    }
    return pi;
}
int main(){
    int n;
    cin>>n;
    cout<<pi(n-1)*4;
    return 0;
}
