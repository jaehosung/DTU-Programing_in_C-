#ifndef __binary_trees__
#define __binary_trees__

#include <iostream>
#include <fstream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class Tree {
    
public:
    Tree();                     // constructor
    ~Tree();                    // destructor
    void insert(int n);         // insert an int
    bool find(int n);           // check if n is in the tree
    Tree * erase(int n);        // erase an element of the tree
    int size(void);             // size of the tree
    int height(void);           // height of the tree
    int min(void);              // minimum element in the tree
    void traverse_pre(void);    // print nodes in pre-order
    void traverse_in(void);     // print nodes in in-order
    void traverse_post(void);   // print nodes in post-order
    void get_pre(vector<int> & v);  // get nodes in pre-order
    void get_in(vector<int> & v);   // get nodes in in-order
    void get_post(vector<int> & v); // get nodes in post-order
    bool operator ==(const Tree &t) const; // check if two trees are equal
    // You don't need to look into this
    // it just implements a method
    // pretty_print()
    // to pretty print a binary tree
#include "binary_tree_pretty_print.cpp"
    
private:
    bool empty;     // flag to specify it tree is empty
    int content;    // content of the node
    Tree *left;     // pointer to left sub-tree
    Tree *right;    // pointer to right sub-tree
};

#endif
