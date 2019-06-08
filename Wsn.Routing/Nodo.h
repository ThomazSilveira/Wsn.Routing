#pragma once
#include "Ponto.h"
class Nodo
{
public:
	Ponto Coordenada;
	char Id;
	Nodo();
	Nodo(Ponto ponto, char id);
	~Nodo();
};

