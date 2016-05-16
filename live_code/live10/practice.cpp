#include <iostream>
#include "linked-list.h"

using namespace std;

class vector{
    
public:
    
    // Constructor method
    vector(void);
    // Destructor method
    ~vector(void);
    
    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);
    
    // User-defined assignment
    vector & operator=(vector &);
    
private:
    // Private members
    // used to implement the class, not meant for the user
    // the vector is implemented as a linked list
    Node<int> * first;
    // the size is kept updated for efficiency
    unsigned int vsize;
    
    // some hidden methods
    void push_backR(int x, Node<int> * & p);
    void erase(void);
    void eraseR(Node<int> * p);
    
};
vector::vector(void){
    first = NULL;
    vsize = 0;
}
// Destructor method
~vector(void){
    erase();    
}

// Other useful methods
unsigned int size(void);
void push_back(int);
int at(unsigned int);
int & vector::operator[](unsigned int){

}

// User-defined assignment
vector & vector::operator=(vector & p){
    delete
}

// Private members
// used to implement the class, not meant for the user
// the vector is implemented as a linked list

// some hidden methods
void push_backR(int x, Node<int> * & p);
void erase(void){
    eraseR(first);
}
void eraseR(Node<int> * p){
    if(first == NULL) return;

    Node<int> p = first->next;
    delete first;
    push_backR(p);
}
int main(void){
    
    // we declare a vector a
    vector a;
    
    // we insert some numbers with push_back
    for(unsigned int i=0; i<10; i++){
        a.push_back(i);
    }
    
    // we access and manipulate some elements in array-style
    for(unsigned int i=2; i<a.size(); i++){
        a[i] = a[i-1] + a[i-2];
    }
    
    // we access some elements usint at()
    cout << "Vector after initialization: " << endl;
    for(unsigned int i=0; i<a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << endl;
    
    vector b;
    // we set b to be equal to a
    b = a;
    cout << "Copy of the vector: " << endl ;
    for(unsigned int i=0; i<b.size(); i++){
        cout << b.at(i) << " ";
    }
    cout << endl;
    
    return 0;
    
}