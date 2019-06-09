#include <iostream>		// cout
#include <vector>		// vector<>
#include "Graph.h"
#include "InputClass.h"
#include "Calculadora.h"

using namespace std;

// ::MAIN::
int main(int argc, char *argv[])
{
	InputClass input;

	input.Entrada_1();

	Calculadora calculadora;

	vector<double> sigmas = calculadora.CalculaSigmas(input);

	// Cria grafo com V nodos
	int V = 5;
	Graph g(V);

	// Cria vertices no grafo
	// E.g. Nodo 0 com Nodo 1, distancia de 2.36

	/*g.addEdge(0, 1, 2.36008474424119);
	g.addEdge(0, 2, 2.46981780704569);
	g.addEdge(1, 2, 4.00124980474851);
	g.addEdge(1, 3, 3.00166620396073);
	g.addEdge(2, 4, 3.30151480384384);
	g.addEdge(3, 4, 4.00499687890016);
	g.addEdge(1, 4, 5.04479930225178);
	g.addEdge(2, 3, 5.14003891035856);*/

	g.addEdge(0, 1, sigmas[0]);
	g.addEdge(0, 2, sigmas[1]);
	g.addEdge(1, 2, sigmas[2]);
	g.addEdge(1, 3, sigmas[3]);
	g.addEdge(2, 4, sigmas[4]);
	g.addEdge(3, 4, sigmas[5]);
	g.addEdge(1, 4, sigmas[6]);
	g.addEdge(2, 3, sigmas[7]);

	// Encontra menores caminhos
	// Partindo do Nodo 0
	g.shortestPath(0);

	g.PrintPathNodes();

	g.PrintDistances();

	char h;
	cin >> h;

	/*Todo: nodo se afastando*/

	/*Todo: nodo voltando*/

	/*Todo: fazer classe de entrada e de saida.*/

}