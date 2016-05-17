#ifndef __graphsA__
#define __graphsA__

#include <set>
#include <map>
#include "graphs.h"

using namespace std;

// Subclass of graphs
// Implementation based on adjacency lists
class GraphA : Graph {
public:
    void print(void);
    void insert(unsigned int u, unsigned int v);
    bool reachable(unsigned int u, unsigned int v);
    void dfs(unsigned int v);
    void bfs(unsigned int v);

private:
    map<unsigned int,set<unsigned int> > adjacencies;
    
    // Some extra methods (recursion)
    bool reachableR(unsigned int u,unsigned int v, set<unsigned int> & visited);
    void dfsR(unsigned int u, set<unsigned int> & visited);
 
};

#endif