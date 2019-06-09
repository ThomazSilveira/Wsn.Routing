/// 
/// pego em: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
///

#include "Graph.h"
#include <string>

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
	this->m_pathNodes = vector<string>(V);
	this->m_distances = vector<double>(V);
}

void Graph::addEdges(conexao *conexoes, vector<double> weigths)
{
	for (int i = 0; i < weigths.size(); i++)
	{
		addEdge(conexoes[i].N1.Id,conexoes[i].N2.Id,weigths[i]);
	}
}

void Graph::addEdge(int u, int v, long double w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
#ifdef _DEBUG
	cout << endl << "DEBUG MODE, SHOW ALL DISTANCES BELOW: ";
#endif

	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

	vector<long double> dist(V, INF);

	// Initialize priority queue values all with 0 distances.
	pq.push(make_pair(0, src));

	dist[src] = 0;

	m_pathNodes[0] = to_string(0);

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
		int u = pq.top().first;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a vertex 
		list<iPair>::iterator i;

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
				pq.push(make_pair(v, dist[v]));
				m_pathNodes[v] = to_string(u) + "-" + to_string(v);

#ifdef _DEBUG
				cout << endl << u << "\t" << v << "\t" << weight << "\t";
#endif

			}
		}

		/*after calculated all better adjacent node, it's time to calculaing the complete rout*/

	}

	for (int i = 0; i < V; ++i) {
		m_distances[i] = dist[i];
	}

#ifdef _DEBUG
	cout << endl;
#endif


}

vector<string> Graph::GetPathNodes()
{
	return this->m_pathNodes;
}

vector<string> Graph::GetDistances()
{
	return vector<string>();
}

void Graph::PrintDistances()
{
	cout << endl;

	for (int i = 0; i < V; ++i) {
		cout << m_distances[i] << endl;
	}

	cout << endl;
}

void Graph::PrintPathNodes()
{
	cout << endl;

	for (int i = 0; i < V; ++i) {
		cout << m_pathNodes[i] << endl;
	}

	cout << endl;
}

