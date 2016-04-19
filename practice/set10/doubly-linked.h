#ifndef __dll__
#define __dll__

#include <iostream>

using namespace std;

// Basic structure to store elements of a list
struct Node {
    int val;        // contains the value
    Node * next;    // pointer to the next element in the list
    Node * prev;    // pointer to the previous element in the list
};

// Class List
class List {
    
public:
    // Constructor
    List(void);
    //Destructor
    ~List(void); 
    // This should insert n in the list
    void insert(int n);
    // This should reverse the list
    void reverse(void);
    // This shoiuld print the list
    void print(void);
    
private:
    // Pointer to the first (if any) element in the list
    Node * first;
};
#endif


