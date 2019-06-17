#pragma once
#include "conexao.h"
#include "Nodo.h"
#include <string>
#include <fstream> //file
#include <sstream>
#include <string>

using namespace std;

class InputClass
{
public:
	int linha;
	int coluna;
	int totalNodos;
	int totalConexoes;

	double **MatrizMapa;
	conexao *Conexoes;
	Nodo *Nodos;

	InputClass();
	~InputClass();

	void PrintNodes();
	void PrintMapa();
	void PrintConexoes();
	void LeRede(string s);
	void LeMapa(string s);
	void Entrada_1();
	void Entrada_2();
};

