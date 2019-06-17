/// 
/// pego em: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
///

#include "Graph.h"
#include <string>

void Graph::MapeiaSaidaParaConexoes()
{
	for (int i = 1; i < m_pathNodes.size(); i++)
	{
		m_pathNodes[i];
	}
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
	this->m_pathNodes = vector<string>(V);
	this->m_distances = vector<double>(V);
}

void Graph::addEdges(conexao *conexoes, vector<double> weigths)
{
	this->Conexoes = vector<conexao>(weigths.size());

	for (int i = 0; i < weigths.size(); i++)
	{
		this->Conexoes[i] = conexoes[i];
		addEdge(conexoes[i].N1.Id, conexoes[i].N2.Id, weigths[i]);
	}
}

void Graph::addEdge(int u, int v, long double w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

OutputClass Graph::shortestPath(int src)
{
#ifdef _DEBUG
	cout << endl << "DEBUG MODE, SHOW ALL DISTANCES BELOW: ";
#endif

	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

	vector<long double> dist(V, INF);

	Path paths = Path(V);

	// Initialize priority queue values all with 0 distances.
	pq.push(make_pair(0, src));

	dist[src] = 0;

	m_pathNodes[0] = to_string(0);

	//paths.insertPath(0, *new conPair(0, *new list<conexao>()));

	//paths.Paths.insert(paths.Paths.begin(), make_pair(0, Conexoes[0]));
	//push_back(make_pair(0, Conexoes[0])); //.insert(0,make_pair(0,Conexoes[0]));


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
			double weight = (*i).second;

			//  If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v 
				dist[v] = dist[u] + weight;
				pq.push(make_pair(v, dist[v]));
				m_pathNodes[v] = to_string(u) + "-" + to_string(v);
				conexao *con = LocalizaConexao(u, v);
				con->setWeigth(weight);
				paths.insereConexaoEm(v, *con);

#ifdef _DEBUG
				cout << endl << u << "\t" << v << "\t" << weight << "\t";
#endif

			}
		}

	}

	for (int i = 0; i < V; ++i) {
		m_distances[i] = dist[i];
	}

#ifdef _DEBUG
	cout << endl;
#endif

	/*apos finalizar cria o caminho total*/
	paths.caminhoCompleto(0);

	OutputClass output = *new OutputClass();
	output.distances = m_distances;
	output.paths = paths;

	return output;
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

conexao * Graph::LocalizaConexao(int n1Id, int n2Id)
{
	for (int i = 0; i < Conexoes.size(); i++)
	{

		if (Conexoes[i].N1.Id == n1Id && Conexoes[i].N2.Id == n2Id)
			return &Conexoes[i];
	}

	return nullptr;
}

