#include <iostream>		// cout
#include <vector>		// vector<>
#include "Graph.h"
#include "InputClass.h"
#include "Calculadora.h"
#include <fstream> 

using namespace std;

// ::MAIN::
int main(int argc, char *argv[])
{
	InputClass input;

	input.LeRede("Inputs\\Exemplo2\\InputEstruturaRede.txt");
	input.LeMapa("Inputs\\Exemplo2\\InputMapa.txt");


	/*TODO: fazer a verificação de cada conexao quanto a superar o threshold de distacia.*/

	Calculadora calculadora;

	vector<double> distancias(input.totalConexoes);

	vector<conexao> conexoesDist(input.totalConexoes);
	for (int i = 0; i < input.totalConexoes; i++)
	{
		conexoesDist[i] = input.Conexoes[i];
	}
	
	distancias = calculadora.CalculaDistancias(conexoesDist);

	vector<double> sigmas = calculadora.CalculaSigmas(input);

	// Cria grafo com V nodos
	Graph g(input.totalNodos);

	g.addEdges(input.Conexoes, sigmas);

	// Encontra menores caminhos
	// Partindo do Nodo 0

	OutputClass output;
	output = g.shortestPath(0);

	g.PrintPathNodes();

	g.PrintDistances();



	/*Todo: nodo se afastando*/

	/*Todo: nodo voltando*/

	/*Todo: saida.*/
	output.EscreveSaida("Inputs\\Exemplo2\\Output.txt");


	char h;
	cin >> h;
}