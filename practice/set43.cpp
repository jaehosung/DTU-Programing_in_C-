#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<float> bag;
    while(true){
        string state;
        float num;
        cin>>state;
        if(state == "quit"){
            break;
        }else if(state == "add"){
            cin >>num;
            bag.insert(num);
        }else if(state == "del"){
            cin >>num;
            if(bag.count(num)>0)
                bag.erase(bag.find(num));
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

