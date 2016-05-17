#ifndef __graphsM__
#define __graphsM__

#include "graphs.h"

using namespace std;

// Subclass of graphs
// Implementation based on matrix
// Limitation: set of nodes must be {1..n}
class GraphM : Graph {
public:
    // New constructor
    GraphM(unsigned int n);
    void print(void);
    void insert(unsigned int u, unsigned int v);
    bool reachable(unsigned int u, unsigned int v);
    void dfs(unsigned int v);
    void bfs(unsigned int v);

private:
    unsigned int n;     // the size of the adjacency matrix
    bool * adjacent;    // the adjacency matrix
    // Some private methods (for recursion)
    bool reachableR(unsigned int u, unsigned int v, bool * &visited);
};


#endif