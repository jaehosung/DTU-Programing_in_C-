#include <iostream>
#include <fstream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include "binary-trees.h"

using namespace std;

Tree::Tree(){
    empty = true;
    left = nullptr;
    right = nullptr;
}

Tree::~Tree(){
    if(empty) return;
    delete left;
    delete right;
}

void Tree::insert(int n){
    
    // if the tree is empty insert n in the root
    if(empty){
        content = n;
        empty = false;
        left = new Tree;
        right = new Tree;
        return;
    }
    
    // compare n with the value of the root
    // and decide if and were to insert n
    if (n == content)
        return;
    else if (n < content)
        left->insert(n);
    else
        right->insert(n);
    
}

bool Tree::find(int n){
    
    // if the tree is empty return false
    if(empty) return false;
    
    // else find in the root or in the sub-trees
    return content == n || left->find(n) || right->find(n) ;
}

Tree * Tree::erase(int n){
    
    // if the tree is empty return this
    if (empty) return this;
 
    // if we have to erase a leaf, just mark it as empty
    if (content == n && left->empty && right->empty)
        empty = true;
    // if we have to erase a node with no right sub-tree, just by-pass
    else if (content == n && left->empty){
        return right;
    }
    // similar for empty left-tree
    else if (content == n && right->empty){
        return left;
    }
    // tricky case: node to be erased has both sub-trees
    else if (content == n){
        // replace content by minimum of right tree
        content = right->min();
        // eliminate the "old" minimum
        Tree * old = right;
        right = right->erase(content);
        if (right != old) delete old;
        return left;
    }
    else if (n < content){
        Tree * old = left;
        left = left->erase(n);
        if (left != old) delete old;
    }
    else if (n > content){
        Tree * old = right;
        right = right->erase(n);
        if (left != old) delete old;
    }
    return this;
}

int Tree::size(void){
    
    // The size of an empty tree is 0
    if(empty) return 0;
    
    // The size of a non-empty tree is 1 (the root)
    // plus the size of the subtrees
    return 1 + left->size() + right->size();
    
}

int Tree::height(void){
    
    // The height of an empty tree is 0
    if(empty) return 0;
    
    // The height of a non-empty tree is 1 (the root)
    // plus the maximum of the heights of the subtrees
    return 1 + max(left->height() , right->height());
    
}

int Tree::min(void){
    
    if(empty) throw std::out_of_range ("the tree is empty!");;
    
    if(left->empty) return content;
    
    return left->min();
    
}

// Methods that implement the three (in, pre, post) traversal methods

void Tree::traverse_pre(void){
    if(empty) return ;
    cout << content << " " ;
    left->traverse_pre();
    right->traverse_pre();
}

void Tree::traverse_in(void){
    if(empty) return ;
    left->traverse_in();
    cout << content << " " ;
    right->traverse_in();
}

void Tree::traverse_post(void){
    if(empty) return ;
    left->traverse_post();
    right->traverse_post();
    cout << content << " " ;
}

void Tree::get_pre(vector<int> & v){
    if(empty) return;
    v.push_back(content);
    left->get_in(v);
    right->get_in(v);
}

void Tree::get_in(vector<int> & v){
    if(empty) return;
    left->get_in(v);
    v.push_back(content);
    right->get_in(v);
}

void Tree::get_post(vector<int> & v){
    if(empty) return;
    left->get_in(v);
    right->get_in(v);
    v.push_back(content);
}

bool Tree::operator ==(const Tree &t) const{
    if (empty && t.empty) return true;
    if (empty) return false;
    if (t.empty) return false;
    return content == t.content && left == t.left && right == t.right;
}

