#include <iostream>		// cout
#include <cmath>		// floor, ceiling, sqrt, pow
#include <cstdlib> 		// abs
#include <vector>		// vector<>
#include <algorithm>	// sort
#include "Ponto.h"
#include "conexao.h"
#include "Graph.h"

using namespace std;

const int linha = 6;
const int coluna = 6;
double mapa[linha][coluna];

double CalculaA(Ponto P1, Ponto P2)
{
	return ((P1.Y - P2.Y) / (P1.X - P2.X));
}

double CalculaB(Ponto P1, double A)
{
	return (P1.Y - (P1.X*A));
}

double CalculaY(Ponto P1, double A, double B)
{
	return ((P1.X*A) + B);
}

double CalculaX(Ponto P1, double A, double B)
{
	return ((P1.Y - B) / A);
}

vector<double> CalculaPontos(double X1, double X2)
{
	vector<double> retorno((int)floor(X2) - (int)floor(X1) + 2);
	retorno[0] = X1;
	for (int i = (int)ceil(retorno[0]); i < floor(X2) - floor(X1) + 1; i++)
	{
		retorno[i] = i;
	}

	retorno[(int)floor(X2) - (int)floor(X1) + 1] = X2;

	return retorno;
}

vector<Ponto> CalculaDimensaoVetor(Ponto P1, Ponto P2)
{
	if (P1.X > P2.X)
		return vector<Ponto>(abs((int)floor(P1.X) - (int)floor(P2.X)) + 1 + abs((int)floor(P2.Y) - (int)floor(P1.Y)) + 1);
	else
		return vector<Ponto>(abs((int)floor(P1.X) - (int)floor(P2.X)) + abs((int)floor(P2.Y) - (int)floor(P1.Y)) + 2);
}

vector<Ponto> CalculaPontosEmXY(Ponto P1, Ponto P2, double a, double b)
{
	int index = 1;
	vector<Ponto> retorno = CalculaDimensaoVetor(P1, P2);
	retorno[0] = P1;
	retorno[retorno.size() - 1] = P2;

#pragma region CalculaValoresDeX
	if (P1.X > P2.X)
	{
		int valor = (int)floor(retorno[0].X);
		for (int i = 0; i < floor(P1.X) - floor(P2.X); i++)
		{
			retorno[index] = *new Ponto(valor, 0);
			retorno[index].Y = CalculaY(retorno[index], a, b);
			valor--;
			index++;
		}
	}
	else if (P2.X > P1.X)
	{
		int valor = (int)ceil(retorno[0].X);
		for (int i = 0; i < floor(P2.X) - floor(P1.X); i++)
		{
			retorno[index] = *new Ponto(valor, 0);
			retorno[index].Y = CalculaY(retorno[index], a, b);
			valor++;
			index++;
		}
	}
#pragma endregion

#pragma region CalculaValoresDeY

	if (P1.Y > P2.Y)
	{
		int valor = (int)floor(retorno[0].Y);
		for (int i = 0; i < floor(P1.Y) - floor(P2.Y); i++)
		{
			retorno[index] = *new Ponto(0, valor);
			retorno[index].X = CalculaX(retorno[index], a, b);
			valor--;
			index++;
		}
	}
	if (P2.Y > P1.Y)
	{
		int valor = (int)ceil(retorno[0].Y);
		for (int i = 0; i < floor(P2.Y) - floor(P1.Y); i++)
		{
			retorno[index] = *new Ponto(0, valor);
			retorno[index].X = CalculaX(retorno[index], a, b);
			valor++;
			index++;
		}
	}

#pragma endregion

	return retorno;
}

vector<Ponto> CalculaPontosEmXY2(Ponto P1, Ponto P2, double a, double b)
{
	int index = 0;
	vector<Ponto> retorno(((int)floor(P2.X) - (int)floor(P1.X)) + ((int)floor(P2.Y) - (int)floor(P1.Y)) + 2);
	retorno[0] = P1;
	retorno[retorno.size() - 1] = P2;
	for (int i = (int)ceil(retorno[0].X); i < floor(P2.X) - floor(P1.X) + 1; i++)
	{
		retorno[i] = *new Ponto(i, 0);
		retorno[i].Y = CalculaY(retorno[i], a, b);
		index++;
	}

	for (int i = (int)ceil(P1.Y); i < floor(P2.Y) - floor(P1.Y) + 1; i++)
	{
		index++;
		retorno[index] = *new Ponto(0, i);
		retorno[index].X = CalculaX(retorno[index], a, b);
	}

	return retorno;
}

struct myclass {
	bool operator() (Ponto i, Ponto j) { return (i.X < j.X); }
} myobject;

vector<double> CalculaDistancias(vector <Ponto> pontos)
{
	vector<double> distancias(pontos.size() - 1);

	for (int i = 0; i < pontos.size() - 1; i++)
	{
		distancias[i] = sqrt(pow((pontos[i].X - pontos[i + 1].X), 2) + pow((pontos[i].Y - pontos[i + 1].Y), 2));
	}

	return distancias;
}

vector<Ponto> CalculaIndiciesDaMatriz(vector <Ponto> pontos)
{
	vector<Ponto> distancias(pontos.size() - 1);

	for (int i = 0; i < pontos.size() - 1; i++)
	{
		distancias[i] = *new Ponto(floor(pontos[i].X), floor(pontos[i].Y));
	}

	return distancias;
}

vector<Ponto> RetiraValoresDuplicados(vector <Ponto> pontos)
{
	vector<Ponto> distancias(pontos.size() - 1);

	for (int i = 0; i < pontos.size(); i++)
	{
		distancias[i] = *new Ponto(floor(pontos[i].X), floor(pontos[i].Y));
	}

	return distancias;
}

double CalculaSigma(Ponto P1, Ponto P2)
{
	/*Calcula A da equacao da reta*/
	double a = CalculaA(P1, P2);
	/*Calcula B da equacao da reta*/
	double b = CalculaB(P1, a);

	/*verificacao se P1.X > P2.X && P1.Y > P2.Y, se sim entao deve alterar de posicao P1=P2 e P2=P1, pois nao cobri o caso em que P1 � maior que P2 em ambas direcoes justamente pq poderia ser corrigido apenas invertendo-os. Demais casos o algoritmo j� trata.*/
	if (P1.X > P2.X && P1.Y > P2.Y)
	{
		Ponto *pAux = &P1;
		P1 = P2;
		P2 = *pAux;
	}

	/*lista com os pontos a serem calculados, agora basta ordenar pelos valores de X*/
	vector<Ponto> Pontos;
	Pontos = CalculaPontosEmXY(P1, P2, a, b);

	/*Ordena o vetor pelos valores de X*/
	std::sort(Pontos.begin(), Pontos.end(), myobject);

	/*calculo de para cada dois pontos da lista calcular sqrt( abs(p1.x - p2.x) + abs( p1.y - p2.y) ), e colocar em um vetor */
	vector<double> distancias;
	distancias = CalculaDistancias(Pontos);

	/*indicies da matriz que deve ser pego o rssi para cada ponto em quest�o, e colocar em um vetor*/
	vector<Ponto> indiciesDaMatriz;
	indiciesDaMatriz = CalculaIndiciesDaMatriz(Pontos);

	/*TODO: pegar na matriz os valores de rssi dos indicies definidos no vetor indiciesDaMatriz*/
	vector<double> rssis(indiciesDaMatriz.size());
	for (int i = 0; i < indiciesDaMatriz.size(); i++)
	{
		rssis[i] = mapa[(int)indiciesDaMatriz[i].X][(int)indiciesDaMatriz[i].Y];
	}

	/*TODO: com o vetor dos indicies e o vetor dos rssi's realizar o calculo final do coeficiente.*/
	double sigma = 0.0;
	for (int i = 0; i < distancias.size(); i++)
	{
		sigma += distancias[i] * rssis[i];
	}

	return sigma;
}

// ::MAIN::
int main(int argc, char *argv[])
{

	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			mapa[i][j] = 0.1;
		}
	}

	mapa[2][0] = 1;
	mapa[2][1] = 1;
	mapa[3][1] = 1;
	mapa[3][0] = 2;
	mapa[4][1] = 1;
	mapa[4][0] = 1;

	mapa[5][1] = 1;
	mapa[4][2] = 1;
	mapa[4][3] = 1;
	mapa[5][3] = 1;
	mapa[5][2] = 2;


	/*Ponto C1*/
	Ponto *c1 = new Ponto(0.8, 2.2);

	/*Ponto N1*/
	Ponto *n1 = new Ponto(2.2, 0.3);

	/*Ponto N2*/
	Ponto *n2 = new Ponto(2.1, 4.3);

	/*Ponto N3*/
	Ponto *n3 = new Ponto(5.2, 0.2);

	/*Ponto N4*/
	Ponto *n4 = new Ponto(5.4, 4.2);

	vector<conexao> conexoes(8);
	conexoes[0] = *new conexao(*c1, *n1);
	conexoes[1] = *new conexao(*c1, *n2);
	conexoes[2] = *new conexao(*n1, *n2);
	conexoes[3] = *new conexao(*n1, *n3);
	conexoes[4] = *new conexao(*n2, *n4);
	conexoes[5] = *new conexao(*n3, *n4);
	conexoes[6] = *new conexao(*n1, *n4);
	conexoes[7] = *new conexao(*n2, *n3);

	vector<double> sigmas(conexoes.size());

	for (int i = 0; i < conexoes.size(); i++) {
		sigmas[i] = CalculaSigma(conexoes[i].P1, conexoes[i].P2);
	}

	// Cria grafo com V nodos
    int V = 5; 
    Graph g(V);

	// Cria vertices no grafo
	// E.g. Nodo 0 com Nodo 1, distancia de 2.36
	g.addEdge(0, 1, 2.36008474424119);
    g.addEdge(0, 2, 2.46981780704569);
    g.addEdge(1, 2, 4.00124980474851);
    g.addEdge(1, 3, 3.00166620396073);
    g.addEdge(2, 4, 3.30151480384384);
    g.addEdge(3, 4, 4.00499687890016);
    g.addEdge(1, 4, 5.04479930225178);
    g.addEdge(2, 3, 5.14003891035856);

	// Encontra menores caminhos
	// Partindo do Nodo 0
    g.shortestPath(0);
	
}