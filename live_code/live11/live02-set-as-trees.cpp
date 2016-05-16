#include <iostream>
#include <vector>
#include "binary-trees.h"

using namespace std;

class Set{

    // Internal implementation of the set as a search tree
private:
    Tree tree;
    
public:
    // A constructor
    Set(){
        // nothing to be done.
    };
    
public:
    // check emptiness
    bool empty(){
        return tree.size()==0;
    }
    
    // add an element to the set
    void insert(int e){
        tree.insert(e);
    }
    
public:
    // check if an element is in the set
    bool contains(int e){
        return tree.find(e);
    };
    
public:
    // delete an element from the set
    void del(int e){
        tree.erase(e);
    };
    
public:
    void print() {
        tree.traverse_in();
    }
    
public:
    ~Set(){
        // nothing to be done.
    };
    
    // This method tests if two sets are equal
    // Is this a correct implementation?
public:
    bool operator ==(Set &S) {
        return tree == S.tree;
        // What about this:
        //vector<int> u;
        //vector<int> v;
        //tree.get_???(u);
        //S.tree.get_???(v);
        //return u == v;
    }
    
};

int main(){
    Set set1, set2;
    
    cout << "Inserting some numbers in S1..." << endl;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.print(); cout << endl;
    
    cout << "Inserting some numbers in S2..." << endl;
    set2.insert(3);
    set2.insert(2);
    set2.insert(1);
    set2.print(); cout << endl;
    
    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;
    
    return 0;
    
}


