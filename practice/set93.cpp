#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> palin;
    bool check = true;
    while(cin.peek() != '\n'){
        int temp;
        cin>>temp;
        palin.push_back(temp);
    }
    for(int i = 0; i<palin.size()/2;i++){
        if(palin[i]!=palin[palin.size()-i-1]){
            check = false;
        }
    }
    if(check) cout<<"yes";
    else cout<<"no";

    return 0;
}
