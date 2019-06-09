/// 
/// pego em: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
///
#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <iomanip>
#include <string>
#include "conexao.h"

#define INF numeric_limits<long double>::max()

using namespace std;

typedef pair<int, long double> iPair;

class Graph
{
	int V; // Total Vertices

	list<iPair> *adj; // List of edges

public:

	Graph(int V);

	void addEdge(int u, int v, long double w);

	void addEdges(conexao *conexoes, vector<double> weigths);

	// src = reference node
	void shortestPath(int src);

	vector<string> GetPathNodes();

	vector<string> GetDistances();

	void PrintDistances();

	void PrintPathNodes();

private:

	vector<string> m_pathNodes;
	vector<double> m_distances;

};
