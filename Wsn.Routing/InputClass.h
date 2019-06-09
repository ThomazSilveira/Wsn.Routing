#pragma once
#include "conexao.h"
#include "Nodo.h"

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

	void Entrada_1();
	void Entrada_2();
};

