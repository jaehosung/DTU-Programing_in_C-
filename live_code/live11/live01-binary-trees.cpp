#include <iostream>
#include "binary-trees.h"

using namespace std;

int main(){
    
    Tree t1,t2;
    
    t1.insert(1);
    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);
    t1.insert(7);
    
    cout << "Printing T1..." << endl;
    t1.printPretty();
    
    t2.insert(4);
    t2.insert(2);
    t2.insert(1);
    t2.insert(3);
    t2.insert(6);
    t2.insert(5);
    t2.insert(7);
    t2.erase(4);
    
    cout << "Printing T2..." << endl;
    t2.printPretty();
    cout << endl;
    
    cout << "T1 has height: " << t1.height() << endl;
    cout << "T2 has height: " << t2.height() << endl;
    cout << endl;
    
    cout << "T1 has size: " << t1.size() << endl;
    cout << "T2 has size: " << t2.size() << endl;
    cout << endl;
    
    cout << "Printing T1 in  PRE-order...";
    t1.traverse_pre();
    cout << endl;
    cout << "Printing T2 in  PRE-order...";
    t2.traverse_pre();
    cout << endl;
    cout << endl;
    
    cout << "Printing T1 in   IN-order...";
    t1.traverse_in();
    cout << endl;
    cout << "Printing T2 in   IN-order...";
    t2.traverse_in();
    cout << endl;
    cout << endl;
    
    cout << "Printing T1 in POST-order...";
    t1.traverse_post();
    cout << endl;
    cout << "Printing T2 in POST-order...";
    t2.traverse_post();
    cout << endl;
    cout << endl;
    
    return 0;
}
