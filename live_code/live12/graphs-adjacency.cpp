#include <iostream>
#include <set>
#include <queue>
#include <map>
#include "graphs-adjacency.h"

using namespace std;

void GraphA::print(void) {
    for(auto i : adjacencies) {
        for(auto j : i.second) {
            // The check serves to avoid printing an edge twice
            if(i.first==j || i.first<j)
                cout << i.first << " -- " << j << endl;
        }
    }
};

void GraphA::insert(unsigned int u, unsigned int v){
    
    // Add the each node to each other's adjacency list
    adjacencies[u].insert(v);
    adjacencies[v].insert(u);
    
}

bool GraphA::reachable(unsigned int u, unsigned int v){
    
    // If any of the nodes does not exist return false
    if( adjacencies.find(u) == adjacencies.end() || adjacencies.find(v) == adjacencies.end())
        return false;
    
    // Create set of visited nodes
    set<unsigned int> visited;
    
    return reachableR(u,v,visited);
}

bool GraphA::reachableR(unsigned int u,unsigned int v, set<unsigned int> & visited){
    
    if (u == v) return true;
    
    visited.insert(u);
    
    for(auto j : adjacencies[u]) {
        if (visited.find(j)==visited.end() && reachableR(j,v,visited)){
            return true;
        }
    }
    return false;
}

// Recursive implementation of DFS
void GraphA::dfs(unsigned int v){
    
    if(adjacencies.find(v)==adjacencies.end()) return;
    
    set<unsigned int> visited;
    dfsR(v,visited);
    return;
}

// Recursive implementation of DFS
void GraphA::dfsR(unsigned int u, set<unsigned int> & visited){
    
    if(visited.find(u)!=visited.end()) return;

    cout << u << " ";
    visited.insert(u);
    for(auto j : adjacencies[u]) {
        dfsR(j,visited);
    }
    return;

}

void GraphA::bfs(unsigned int v){
    
    if(adjacencies.find(v)==adjacencies.end()) return;
    
    set<int> visited;
    queue<int> open;
    int p = v;
    
    open.push(p);
    while(!open.empty()){
        p = open.front();
        open.pop();
        if(visited.find(p)==visited.end()){
            cout << p << " ";
            for(auto j : adjacencies[p]) {
                if (visited.find(j)==visited.end()){
                    open.push(j);
                }
            }
            visited.insert(p);
        }
    }
}