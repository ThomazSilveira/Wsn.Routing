#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <iomanip>
#include <string>

#define INF 0x3f3f3f3f

typedef std::pair<int, long double> iPair;

class Graph
{
	int V; // Total Vertices

	std::list<iPair> *adj; // List of edges

public:

	Graph(int V);

	void addEdge(int u, int v, long double w);

	// src = reference node
	void shortestPath(int src);

	std::vector<std::string> GetPathNodes();

	std::vector<std::string> GetDistances();

	void PrintDistances();

	void PrintPathNodes();

private:

	std::vector<std::string> m_pathNodes;
	std::vector<double> m_distances;

};
