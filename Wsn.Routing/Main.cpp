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
	Graph g(input.totalNodos);

	g.addEdges(input.Conexoes, sigmas);

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