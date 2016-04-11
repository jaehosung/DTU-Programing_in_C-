#include<iostream>
#include<string>
#include<vector>

using namespace std;

int leven( string word1, string word2){
    if(word1.size()==0){
        return word2.size();
    }else if(word2.size()==0){
        return word1.size();
    }else{

        string _w1 = word1;
        string _w2 = word2;
        int le1 = leven(word1.erase(0,1),_w2)+1;
        int le2 = leven(_w1,word2.erase(0,1))+1;
        int le3 = leven(word1,word2)+((_w1[0]==_w2[0])? 0:1);
        return min(le1,min(le2,le3));
    }
}

int main(){
    string word1,word2;
    cin>>word1>>word2;

    cout<<leven(word1,word2);

    return 0;
}
