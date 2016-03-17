#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,m,l,i;// l : intervals; n :size;
    int *input;
    int *output;
    int max=0,interval;
    cin>>l>>n;
    input = new int[n];
    for(i=0;i<n;i++){
        cin>>input[i];
        if(input[i]>max)
            max = input[i];
    }
    interval = ceil((double)max/l);
    output = new int[l];
    for(i=0;i<l;i++){
        output[i]=0;
    }
    for(i=0;i<n;i++){
        output[input[i]/interval]++;
    }
    for(i=0;i<l;i++){
        cout<<i*interval<<": "<<output[i]<<endl;
    }
    return 0;
}
