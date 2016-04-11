#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> reverseList;
    int temp;
    while(cin>>temp){
        reverseList.push_back(temp);
    }
    for(int i = reverseList.size()-1;i>=0;i--){
        cout<<reverseList[i]<<" ";
    }
    return 0;

}
