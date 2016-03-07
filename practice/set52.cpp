#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    char type,num;
    vector<char> vecA;
    vector<char> vecB;

    while( cin.peek() !='\n'){
        cin>>type>>num;
        if(type =='a'){
            vecA.push_back(num);
        }else{
            vecB.push_back(num);
        }
    }
    for(int i = 0; i< max(vecA.size(),vecB.size()); i++){
        if(vecA.size()>i){
            cout<<vecA[i]<<" ";
        }
        if(vecB.size()>i){
            cout<<vecB[i]<<" ";
        }
    }

    return 0;
}
