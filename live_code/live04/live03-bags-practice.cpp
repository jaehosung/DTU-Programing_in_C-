#include <iostream>
#include <string>
#include <set>
using namespace std;

#define MAX_ARRARY 100
typedef enum {add, display, none} action;
typedef struct Item{
    int value;
    Item *nextItem;
}Item;

typedef struct{
    //array
    bool bagArray[MAX_ARRARY];
    //linked list
    Item *startItem;
    //set
    set<int> bagSet;

}Bag;

void initialise(Bag &bag){
    //Array initialise
    for( int i = 0; i < MAX_ARRARY ; i++){
        bag.bagArray[i]=false;
    }
    //linked list initialise;
    bag.startItem = NULL;
}

void displayBag(Bag bag){

    for( int i = 0; i < MAX_ARRARY; i++){
        if(bag.bagArray[i]==true){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    Item *tempItem = bag.startItem;
    while(true){
        if(tempItem!=NULL){
            cout<<(*tempItem).value<<" ";
            tempItem = (*tempItem).nextItem;
        }else{
            break;
        }
    }
    cout<<endl;
    set<int>::iterator itr;
    for(itr=(bag.bagSet).begin();itr!=(bag.bagSet).end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}

action str2action(string str){
    if(str=="add") return add;
    if(str=="display") return display;
    return none;
}

void insert(Bag &bag, int x){
    //Array Insert
    bag.bagArray[x]=true;

    //Linked list Insert
    Item * i = new Item;
    i->value = x;
    i->nextItem = bag.startItem;
    bag.startItem = i;

    bag.bagSet.insert(x);

}
void update(Bag &bag, action act,int x){
    switch(act){
        case add :
            insert(bag,x);
            break;
        default :
            break;
    }
}



int main(){
    Bag bag;
    string action;
    int x;

    initialise(bag);

    while(true){
        displayBag(bag);
        cin>>action>>x;
        update(bag,str2action(action),x);
    }
}
