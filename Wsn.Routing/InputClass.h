#pragma once
#include "conexao.h"
#include "Nodo.h"

class InputClass
{
public:
	double **MatrizMapa;
	conexao *Conexoes;
	Nodo *Nodos;
	InputClass();
	InputClass(double **matriz,conexao *conexoes,Nodo *nodos);
	~InputClass();
};

