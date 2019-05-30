#include "Graph.h"

// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new std::list<iPair> [V];
} 


void Graph::addEdge(int u, int v, long double w) 
{ 
    adj[u].push_back(std::make_pair(v, w)); 
    adj[v].push_back(std::make_pair(u, w)); 
    
}

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
    // Create a priority queue to store vertices
    std::priority_queue< iPair, std::vector <iPair> , std::greater<iPair> > pq;

    // Create a vector for distances and initialize all
    std::vector<long double> dist(V, INF); 
  
    // Initialize priority queue values all with 0 distances.
    pq.push(std::make_pair(0, src)); 

    dist[src] = 0; 
  
    // Looping till priority queue becomes empty 
    // (or all distances are not finalized)
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        std::list<iPair>::iterator i; 

        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of 
            // current adjacent of u.
            int v = (*i).first; 
            long double weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(std::make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %Lf\n", i, dist[i]); 
}
