#pragma once
#include "Ponto.h"
#include <iostream>		// cout

class Nodo
{
public:
	static Nodo *findNode(Nodo *nodos, int size, int id);
	static void imprimeNodes(Nodo * nodos, int size);
	Ponto Coordenada;
	int Id;
	double bateria;
	Nodo();
	Nodo(Ponto ponto, int id, double bateria);
	~Nodo();
};

