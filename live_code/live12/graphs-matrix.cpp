#include <iostream>
#include <stack>
#include <queue>
#include "graphs-matrix.h"

using namespace std;

// Subclass of graphs
// Same signature as the abstract class
// Implementation based on matrix
// Limitation: set of nodes must be {1..n}

GraphM::GraphM(unsigned int n){
    this->n = n;
    adjacent = new bool[n*n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adjacent[i*n+j]=false;
        }
    }
}

void GraphM::print(void){
    for(int i=0; i<n; i++){
        // Note that we start from the diagonal
        // to avoid printing an edge twice
        for(int j=i; j<n; j++){
            if(adjacent[i*n+j]){
                cout << i << " -- " << j << endl;
            }
        }
    }
}

void GraphM::insert(unsigned int u, unsigned int v){
    
    // We just need to set the corresponding cells A[u,v] and A[v,u] to true
    adjacent[u*n+v] = true;
    adjacent[v*n+u] = true;

}

bool GraphM::reachable(unsigned int u, unsigned int v){
    
    bool * visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    bool r = reachableR(u,v,visited);
    delete visited;
    return r;
    
}

bool GraphM::reachableR(unsigned int u, unsigned int v, bool * &visited){
    
    if (u == v) return true;
    
    visited[u] = true;
    
    for(int i = 0; i<n; i++){
        if (!visited[i] && adjacent[u*n+i] && reachableR(i,v,visited)){
            return true;
        }
    }
    return false;
}


// Iterative implementation of DFS
void GraphM::dfs(unsigned int v){
    bool * visited = new bool[n];
    stack<int> open;
    int u;
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    open.push(v);
    while(!open.empty()){
        u = open.top();
        open.pop();
        if(!visited[u]){
            visited[u] = true;
            cout << u << " ";
            for(int j = 0; j<n; j++){
                if (adjacent[u*n+j] && !visited[j]){
                    open.push(j);
                }
            }
        }
    }
    delete visited;
}

void GraphM::bfs(unsigned int v){
    bool * visited = new bool[n];
    queue<int> open;
    int u;
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    open.push(v);
    while(!open.empty()){
        u = open.front();
        open.pop();
        if(!visited[u]){
            visited[u] = true;
            cout << u << " ";
            for(int j = 0; j<n; j++){
                if (adjacent[u*n+j] && !visited[j]){
                    open.push(j);
                }
            }
        }
    }
    delete visited;
}