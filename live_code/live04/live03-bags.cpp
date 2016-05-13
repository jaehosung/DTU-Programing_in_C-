#include <iostream>
#include <set> // http://www.cplusplus.com/reference/set/set/

using namespace std;

// enumeration type for actions on the bag
typedef enum action {add , display, none} action;

// translation of strings into actions
action str2action(string s){
    if (s=="add") return add;
    if (s=="display") return display;
    return none;
}

// a place in the bag (name declaration)
//struct place;

// a place in the bag (full declaration)
typedef struct item {
    unsigned int val;
    item * next;
} item;

#define BAG_AS_ARRAY_SIZE 100

// We will implement a bag in three ways
typedef struct {
    bool as_array[BAG_AS_ARRAY_SIZE];   // using arrays
    item * as_linked_items;             // using linked lists
    set<unsigned int> as_set;           // using sets
} bag;
// We do it for pedagogical purposes
// mainly to emphasize the differences
// We will try to keep the three bags aligned
// but (for pedagogical purposes) the following code fails in doing so

// Simple function to initialise the bag initialise through call by reference
void initialise(bag & b){

    // Array
    for(int i=0; i<BAG_AS_ARRAY_SIZE; i++){
        b.as_array[i] = false;
    }
    
    // Linked list
    b.as_linked_items = nullptr;
    
    // Set: nothing to be done :)
}

// function to display the content of the bag
void display_bag(bag b){

    cout << "The bag is : " << endl;

    // Array
    cout << " - (A) - : " ;
    for(int i=0; i<BAG_AS_ARRAY_SIZE; i++){
        if(b.as_array[i])
            cout << i << " " ;
    }
    cout << endl;

    // Linked List
    cout << " - (L) - : " ;
    item * p = b.as_linked_items;
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next; // same as (*p).next
    }
    cout << endl;

    // Set
    cout << " - (S) - : ";
    for(auto e : b.as_set)
        cout << e << " " ;
    cout << endl;
    
    return;

}

void insert(bag &b,unsigned int x){
    
    // Array
    b.as_array[x] = true;

    // Linked list
    // we allocate a new place for the new value
    item * i = new item;
    i->val = x;
    // we make it point to the bag
    i->next = b.as_linked_items;
    // we set the bag now to start with the new place
    b.as_linked_items = i;
    
    // Set
    b.as_set.insert(x);
    
}

// this function deals with actions on a bag
void update(bag &b, action a, unsigned int x){
    
    switch(a){
        case add:
            insert(b,x);
            break;
        case none: break;
        default: break;
    }
    
    return;
}

int main(){
    
    bag my_bag;
    string my_act_str;
    unsigned int x;
    
    initialise(my_bag);
    
    while(true){
        
        display_bag(my_bag);
        cout << "What's next? (actions = add x , display)" << endl;
        cin >> my_act_str;
        cin >> x;
        update(my_bag,str2action(my_act_str),x);
        
    }
    
    return 0;
    
}
