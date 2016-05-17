#ifndef __graphs__
#define __graphs__

// Abstract class of undirected graphs
class Graph {
public:
    virtual void print(void) = 0;
    virtual void insert(unsigned int u, unsigned int v) = 0;
    virtual bool reachable(unsigned int u, unsigned int v) = 0;
    virtual void dfs(unsigned int v) = 0;
    virtual void bfs(unsigned int v) = 0;
};

#endif