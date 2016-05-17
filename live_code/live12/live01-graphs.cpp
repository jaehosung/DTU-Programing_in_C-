#include <iostream>
#include "graphs-matrix.h"
#include "graphs-adjacency.h"

using namespace std;

int main(void){
    
    //GraphM g(10);
    GraphA g;
    
    // The graph of the slides
    //g.insert(0,1);
    //g.insert(1,2);
    //g.insert(2,0);
    //g.insert(2,3);
    //g.insert(3,0);
    
    // A tree-shaped graph
    g.insert(0,1);
    g.insert(0,2);
    g.insert(1,3);
    g.insert(1,4);
    g.insert(2,5);
    g.insert(2,6);
    
    cout << "Printing the graph..." << endl;
    g.print();
    cout << endl;
    
    unsigned int source = 0;
    unsigned int target = 3;
    cout << "Can we reach " << target << " from " << source << "?... "
    << (g.reachable(source,target)?"YES!":"NO!") << endl;
    cout << endl;
    source = 0;
    target = 7;
    cout << "Can we reach " << target << " from " << source << "?... "
    << (g.reachable(source,target)?"YES!":"NO!") << endl;
    cout << endl;
    
    cout << "DFS enumeration..." << endl;
    g.dfs(0);
    cout << endl;
    cout << endl;
    
    cout << "BFS enumeration..." << endl;
    g.bfs(0);
    cout << endl;
    
    return 0;
    
}