#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> bag;
    while(true){
        string state;
        int num;
        cin>>state;
        if(state == "quit"){
            break;
        }else if(state == "add"){
            cin >>num;
            bag.insert(num);
        }else if(state == "del"){
            cin >>num;
            bag.erase(num);
        }else if(state == "qry"){
            cin >>num;
            if(bag.count(num)!=0){
                cout<<"T";
            }else{
                cout<<"F";
            }
        }
    }
}

