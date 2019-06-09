#pragma once
#include "Ponto.h"
#include <cmath>		// floor, ceiling, sqrt, pow, fmod
#include <algorithm>	// sort
#include <vector>		// vector<>
#include "conexao.h"
#include "InputClass.h"

using namespace std;

class Calculadora
{
private:
	InputClass m_input;
	double CalculaA(Ponto P1, Ponto P2);
	double CalculaB(Ponto P1, double A);
	double CalculaY(Ponto P1, double A, double B);
	double CalculaX(Ponto P1, double A, double B);
	vector<double> CalculaPontos(double X1, double X2);
	vector<Ponto> CalculaDimensaoVetor(Ponto P1, Ponto P2);
	vector<Ponto> CalculaPontosEmXY(Ponto P1, Ponto P2, double a, double b);
	vector<Ponto> CalculaPontosEmXY2(Ponto P1, Ponto P2, double a, double b);
	vector<double> CalculaDistancias(vector <Ponto> pontos);
	vector<Ponto> RetiraValoresDuplicados(vector <Ponto> pontos);
	vector<Ponto> CalculaIndiciesDaMatriz(vector <Ponto> pontos);
public:
	vector<double> CalculaDistancias(vector<conexao> conexoes);
	double CalculaSigma(Ponto P1, Ponto P2);
	vector<double> CalculaSigmas(InputClass input);
	Calculadora();
	~Calculadora();
};

