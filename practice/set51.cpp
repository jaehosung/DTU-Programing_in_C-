#include<iostream>
#include<algorithm>
#include<vector>
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
    sort(vecA.begin(),vecA.end());
    sort(vecB.begin(),vecB.end());
    for(int i = 0; i< vecA.size(); i++){
            cout<<vecA[i]<<" ";
    }

    for(int i = 0; i< vecB.size(); i++){
            cout<<vecB[i]<<" ";
    }
    return 0;
}
