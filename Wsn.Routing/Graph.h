#pragma once
#include <iostream>
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

typedef std::pair<int, long double> iPair;

class Graph 
{ 
    int V; // Total Vertices

    std::list<iPair> *adj; // List of edges
  
public: 

    Graph(int V);
  
    // add an edge to graph
    // v = node p2
    // u = node p1
    // w = edges' weight
    void addEdge(int u, int v, long double w); 
  
    // prints shortest path from s
    // src = reference node
    void shortestPath(int src); 
}; 
