#ifndef DIRECTED_GRAPH_H

#define DIRECTED_GRAPH_H

#include<iostream>
#include<vector>

using namespace std;

class Graph{
public:
//use a vector of int_vectors to implement an adjacent list.
    vector<vector<int> > adjList;
    unsigned vertexNum;//the number of vertice in the graph.
    
    //A constructor
    Graph(unsigned n){
        vector<vector<int> > temp(n);
        adjList = temp;
        vertexNum = n;
    }
    
    
    void addEdge(int src, int dest ){ 
        this->adjList[src].push_back(dest);
        
    }
    
    void printGraph(){//adjList[0] is a sentinel, not used.
        for (int v = 1; v < (this->vertexNum); ++v) {
            cout << "\n Adjacency list of vertex " << v
                << "\n head ";
            for (auto x : this->adjList[v])
                cout << "-> " << x;
                printf("\n");
        }
    }
    
};


#endif