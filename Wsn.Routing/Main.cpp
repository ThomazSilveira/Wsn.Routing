#include<stdio.h>
#include "Ponto.h"
#include <math.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

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
		//for (int i = 0; i < floor(P1.X) - floor(P2.X) + 1; i++)
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
		for (int i = 0; i < floor(P1.Y) - floor(P2.Y) + 1; i++)
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
		distancias[i] = *new Ponto(floor(pontos[i].X),floor(pontos[i].Y));
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

int main(int argc, char *argv[])
{
	/*Pontos de teste 1,, no qual P1 é menor em X e em Y comparado com o P2*/
	Ponto *p1 = new Ponto(0.8, 0.8);
	Ponto *p2 = new Ponto(2.7, 1.3);

	/*Pontos de teste 2, no qual P1 é maior em X e menor Y comparado com o P2 Obs.: neste caso ira gerar valor duplicado pq tanto em X e em Y as barreiras colidem igual*/
	//Ponto *p1 = new Ponto(5.2, 0.8);
	//Ponto *p2 = new Ponto(2.2, 1.3);

	/*Pontos de teste 3, no qual P1 é menor em X e maior em Y comparado com o P2*/
	//Ponto *p1 = new Ponto(0.8, 2.7);
	//Ponto *p2 = new Ponto(5.2, 1.1);

	/*Pontos de teste 4, no qual P1 é maior em X e em Y comparado com o P2*/
	//Ponto *p1 = new Ponto(5.2, 1.3);
	//Ponto *p2 = new Ponto(2.2, 0.8);

	/*Pontos de teste 5, no qual caminha só em X*/
	//Ponto *p1 = new Ponto(1.3, 5.4);
	//Ponto *p2 = new Ponto(6.2, 5.4);

	/*Pontos de teste 5, no qual caminha só em Y*/
	//Ponto *p1 = new Ponto(2.1, 3.8);
	//Ponto *p2 = new Ponto(2.1, 7.2);


	/*Calcula A da equacao da reta*/
	double a = CalculaA(*p1, *p2);
	/*Calcula B da equacao da reta*/
	double b = CalculaB(*p1, a);

	/*verificacao se P1.X > P2.X && P1.Y > P2.Y, se sim entao deve alterar de posicao P1=P2 e P2=P1, pois nao cobri o caso em que P1 é maior que P2 em ambas direcoes justamente pq poderia ser corrigido apenas invertendo-os. Demais casos o algoritmo já trata.*/
	if (p1->X > p2->X && p1->Y > p2->Y)
	{
		Ponto *pAux = p1;
		p1 = p2;
		p2 = pAux;
	}

	/*lista com os pontos a serem calculados, agora basta ordenar pelos valores de X*/
	vector<Ponto> Pontos;
	Pontos = CalculaPontosEmXY(*p1, *p2, a, b);

	/*Ordena o vetor pelos valores de X*/
	std::sort(Pontos.begin(), Pontos.end(), myobject);

	/*TODO: excluir valores repetidos do vector {Pontos}, e ficar em duvida sobre o pq disso deixa q eu faço depis nao vamo perde tempo tentando compreender oq ja foi feito kkkk*/

	/*calculo de para cada dois pontos da lista calcular sqrt( abs(p1.x - p2.x) + abs( p1.y - p2.y) ), e colocar em um vetor */
	vector<double> distancias;
	distancias = CalculaDistancias(Pontos);

	/*indicies da matriz que deve ser pego o rssi para cada ponto em questão, e colocar em um vetor*/
	vector<Ponto> indiciesDaMatriz;
	indiciesDaMatriz = CalculaIndiciesDaMatriz(Pontos);

	/*TODO: pegar na matriz os valores de rssi dos indicies definidos no vetor indiciesDaMatriz*/


	/*TODO: com o vetor dos indicies e o vetor dos rssi's realizar o calculo final do coeficiente.*/


}